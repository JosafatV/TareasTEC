#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
// Include OpenCL headers 
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#include <CL/cl.h>
#endif
// the kernel is loaded as a str/char* this defines the maximum size it can have
#define MAX_SOURCE_SIZE (0x100000)
 
int main(void) {
    // Create the input vectors
    int i, j;
    const int COL = 10000;
	const int ROW = 10000;
	// change to RANDOM values
	const int X_val = 1;
    int *A = (int*)malloc(sizeof(int)*COL);
    int *B = (int*)malloc(sizeof(int)*ROW);

    // Init the vectors 
    for(i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			A[i] = i+1;
			B[i] = i*4+j;
		}
    }

	double start = omp_get_wtime();
 
    // Load the kernel source code into the array source_str
    FILE *fp;
    char *source_str;
    size_t source_size;
    // Read the kernel
    fp = fopen("matrixmul.cl", "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(1);
    }

    source_str = (char*)malloc(MAX_SOURCE_SIZE);
    source_size = fread( source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose( fp );
 
    //1. Get platform and device information
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;   
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_GPU, 1, 
            &device_id, &ret_num_devices);
 
    //2. Create an OpenCL context
    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);
 
    // Create a command queue
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
 
    // Create memory buffers on the device for each vector 
    cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, 
            ROW*COL * sizeof(int), NULL, &ret);
    cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
            ROW*COL * sizeof(int), NULL, &ret);
    cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, 
            ROW*COL * sizeof(int), NULL, &ret);
 
    // Copy the input lists to their respective memory buffers
    ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0,
            ROW*COL * sizeof(int), A, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, 
            ROW*COL * sizeof(int), B, 0, NULL, NULL);
 
    //3. Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1, 
            (const char **)&source_str, (const size_t *)&source_size, &ret);
 
    // Build the program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
 
    //4. Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "matrixmul", &ret);
 
    // Set the arguments of the kernel
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&a_mem_obj);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&c_mem_obj);
 
    //5. Execute the OpenCL kernel on the list
    size_t global_item_size = ROW*COL; // Process the entire lists
    size_t local_item_size = 64; // Divide work items into groups of 64
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, 
            &global_item_size, &local_item_size, 0, NULL, NULL); // queue more than 1, 1D
 
    // Read the memory buffer on the device to the local ouptut variable Z
    int *C = (int*)malloc(sizeof(int)*ROW*COL);
    ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, 
            ROW*COL * sizeof(int), C, 0, NULL, NULL);
 
	printf("+++ MX_MUL with SIZE %dx%d took: %.7f +++ \n", ROW,COL, omp_get_wtime()-start);
 	
    // Display the result to the screen
    /*for(i = 0; i < ROW; i++) {
		printf ("| ");
		for (j=0; j < COL; j++) {
			printf ("%d | ", C[i*ROW+j]);
		}
		printf ("\n");
	}*/
 
    //6. Clean up
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(a_mem_obj);
    ret = clReleaseMemObject(b_mem_obj);
    ret = clReleaseMemObject(c_mem_obj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    free(A);
    free(B);
	free(C);
	
    // Be nice
    printf("Matrix Multiplication with OpenCL completed\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>

typedef struct Node{
  int value;
  struct Node * next;
} Node_t;

//prints the ids of the package
void print_list(Node_t* head);
void push_back(Node_t** head, int value);
void push_front(Node_t** head, int value);

//returns the id of the popped element
int pop_front(Node_t** head);
int pop_back(Node_t* head);
int remove_at(Node_t** head, int index);

//returns the package at a position
int get_at(Node_t* head, int index);

//sets the package at a position
int set_at(Node_t *head,  int index, int value);

//swaps the content of two nodes
void swap(Node_t* head, int index1, int index2);

//returns the length of the list
int get_length(Node_t* head);

int main () {
	int alpha = rand()%21+5;
	int length = 10000;
	Node_t* x = NULL;
	Node_t* y = NULL;
	Node_t* z = NULL;

	srand(time(NULL));
	
	// Create vectors in memory and intialize variables
	for (int i = 0; i<length; i++) {
		push_back(&x, rand() % 101);
		push_back(&y, rand() % 101);
		push_back(&z, 0);
	}

	//printf("X is: "); print_list(x);
	//printf("Y is: "); print_list(y);

	double start = omp_get_wtime();

	// Compute
	for (int i = 0; i<length; i++) {
		int rez = get_at(x, i)*alpha + get_at(y, i);
		set_at(z, i, rez);
	}

	//printf("Z is: "); print_list(z);
	printf("Execution took %f seconds, vector length: %d \n", omp_get_wtime()-start, length);

	return 0;
}


void print_list(Node_t *head) {
  Node_t * current = head;
  printf("[");
  while(current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
  printf("]\n");
}

void push_back(Node_t **head, int value) {
  //if list is empty
  Node_t * current = *head;
  if (current == NULL){
    push_front(head, value);
    return;
  }
  //go to end of list
  while(current->next != NULL){
    current = current->next;
  }
  //add new element
  current->next = malloc(sizeof(Node_t));
  current->next->value = value;
  current->next->next = NULL;
}

void push_front(Node_t **head, int value) {
  Node_t * new_node;
  //allocates memory for new node
  new_node = malloc(sizeof(Node_t));
  new_node->value =  value;
  new_node->next = *head;
  //assigns new head
  *head = new_node;
}

int pop_front(Node_t **head) {
  int retval = -1; // change to NaN or other error condition
  Node_t* new_head = NULL;

  //if list is empty
  if(*head == NULL){
    return retval;
  }

  new_head = (*head)->next;
  retval = (*head)->value;
  free(*head);
  *head = new_head;

  return retval;
}

int pop_back(Node_t* head) {
  int retval = -1; // change to NaN or other error condition

  if(get_length(head) == 0){
    printf("List is already empty. Cannot pop-back.\n");
    return retval;
  }

  //If there is only one item in the list
  if(head->next == NULL){
    retval = head->value;
    free(head);
    return retval;
  }

  //Go to the second last node
  Node_t * current = head;
  while(current->next->next != NULL){
    current = current->next;
  }

  retval = current->next->value;
  free(current->next);
  current->next = NULL;
  return retval;
}

int remove_at(Node_t **head, int index) {
  if(get_length(*head) <= index || index < 0){
    printf("Cannot remove, index out of range\n");
    return -1; // change to NaN or other error condition
  }

  int i = 0;
  int retval = -1; // change to NaN or other error condition

  Node_t * current = *head;
  Node_t * temp = NULL;

  //first element
  if(index == 0){
    return pop_front(head);
  }

  for(i = 0; i < index - 1; ++i){
    //the index is out of range
    if(current->next == NULL){
      printf("Index out of range");
      return -1; // change to NaN or other error condition
    }
    current = current->next;
  }

  temp = current->next;
  retval = temp->value;
  current->next = temp->next;
  free(temp);

  return retval;
}

int get_length(Node_t *head) {
  Node_t * current = head;
  int retval = 0;
  while(current != NULL){
    current = current->next;
    retval ++;
  }
  return retval;
}

int get_at(Node_t *head, int index) {
  int retval = -1; // change to NaN or other error condition

  if(get_length(head) <= index || index < 0){
    printf("Index out of range. Cannot get at %d.\n", index);
    return retval;
  }

  Node_t * current = head;

  for(int i = 0; i < index; ++i){
    current = current->next;
  }
  retval = current->value;

  return retval;
}

int set_at(Node_t *head,  int index, int value) {
  int retval = -1; // change to NaN or other error condition

  if(get_length(head) <= index || index < 0){
    printf("Index out of range. Cannot set at %d.\n", index);
    return retval;
  }

  Node_t* current = head;

  for(int i = 0; i < index; ++i){
    current = current->next;
  }
  current->value = value;
  retval = current->value;

  return retval;
}

void swap(Node_t *head, int index1, int index2) {
  int length = get_length(head);
  if(index1 >= length || index1 < 0 || index2 >= length || index2 < 0){
    printf("Index out of range. Cannot swap %d and %d.\n", index1, index2);
    return;
  }

  int temp;
  temp = get_at(head, index1);
  set_at(head, index1, get_at(head,index2));
  set_at(head,index2, temp);

}

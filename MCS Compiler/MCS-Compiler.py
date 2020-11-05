# Instituto Tecnologico de Costa Rica
# Evaluating Many-Core Symulators
#
# MCS-Compiler (DS3) 
#
# 
# Josafat Vargas
# 25th of October, 2020

from fileManager import *

def_comment = "# Configuration file for DS3 Simulator\n# Created with MCS Compiler \n \n"
def_job_name = "job_name "
def_tasks = "add_new_tasks "
newline = "\n"
head = "HEAD"
tail = "TAIL"
task_id = 0

def parse_input ():
    # identify tasks [function_name, arguments_in, return_out]
    job_lists = [["ffst", 0, 1000], ["ssnd",1000,2000], ["ttrd",2000,1000]]
    #job_lists = [["ffst", 0, 1000], ["ssnd",1000,2000], ["ttrd",2000,1000],["ffth", 1000, 500], ["vvth", 1000, 500], ["ssth", 1000, 0]] 

    # identify relationships [task_id_src, task_id_dest, data_volume]
    job_relations = [[0,1,100], [1,2,100]]
    #job_relations = [[0,1,100], [1,2,100], [2,3,100], [2,4,100], [4,5,100], [3,5,100]]

    # create file
    master_string = ""
    master_string += def_comment
    master_string += def_job_name + input_file_name[0:len(input_file_name)-4] + newline
    master_string += def_tasks + str(len(job_lists)) + newline

    print ("Creating File")
    output_file_name = "job_"+input_file_name
    writeFile(output_file_name, master_string)

    # add tasks to file
    for task_id in range (len(job_lists)):
        master_string = ""
        master_string += job_lists[task_id][0] + " " + str(task_id)
        # define task dependencies
        for j in range (len(job_relations)):
            if (task_id == job_relations[j][1]):
                master_string += " " + str(job_relations[j][0])
        master_string += newline
        # add HEAD or TAIL markers
        if (task_id == 0):
            master_string += job_lists[task_id][0] + " " + head + newline
        if (task_id == len(job_lists)-1):
            master_string += job_lists[task_id][0] + " " + tail + newline
        #set values for task parameters
        master_string += job_lists[task_id][0] + " earliest_start 0 deadline 10000 " + "input_vol " + str(job_lists[task_id][1]) + " output_vol " +  str(job_lists[task_id][2]) + newline
        appendFile(output_file_name, master_string)

    # add communication volumes to file
    appendFile(output_file_name, newline + "# Communication volume for the tasks that have dependencies\n" + newline)
    for rel_id in range (len(job_relations)):
        master_string = "comm_vol " + str(job_relations[rel_id][0]) + " " + str(job_relations[rel_id][1]) + " " + str(job_relations[rel_id][2]) + newline
        appendFile(output_file_name, master_string)


    return 0



input_file_name = input ("File name: ")

#read_data = readFile(input_file_name)

parse_input()

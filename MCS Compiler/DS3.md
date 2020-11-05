*************************************************************************
   	© Copyright 2020 ASU All rights reserved.
      This file contains confidential and proprietary
 	    information of DASH-SoC Project.
*************************************************************************
# 1. Installation Guide :

Python 3.6 is recommended. Other package versions may also be supported. 
These packages can be installed using either Anaconda or Pip. Download the source code from https://github.com/segemena/DS3.git 

```
git clone https://github.com/segemena/DS3.git 
```

## 1.1 Install Dependencies

On Ubuntu or Debian Linux install pip3 with:

```
sudo apt-get install python3-pip
```

On Fedora Linux, enter:
```
sudo yum install python3-pip
```

With pip3 installed you can install all dependencies with:
```
pip3 install numpy==1.17.3 pandas tensorflow Keras simpy networkx scipy docplex matplotlib pydotplus ipython pytest scikit_learn
```

If newer versions of the dependencies are not compatible, reinstall specifying the versions available in the requirements.txt file.

# 2. How to run the program?
There are basically 4 relevant files: a config_file.ini that manages the which files the program will run, a resource file (SoC.\*.txt) which has the hardware definitions, a tasks file (job_\*.txt) which is the application and tasks to be simulated and a scheduler file (scheduler.py) where the different type of scheduler algorithms are written.

There is documentation in all the files for the specifics of use and an html doxygen older with a more expansive manual. Additional files are described in 3.3

## 2.1 Job File (config_Jobs folder)
Create a Task list in a text file (job_*.txt) using the key word add_new_tasks followed by the task list.
```
The format: add_new_tasks $num_of_tasks (int)
            $task_name (string) $task_id (int) $task_predecessors (list)
```

Example: The following lines add a new task with ID=0, and predecessor for this task is task with ID=2
(empty list means there is no dependency) 
```
add_new_tasks 1
scrambler 0 2
```

## 2.2 SoC Configuration File (config_SoC folder)
Create a Resource list in a text file (SoC.*.txt) using the key word add_new_resource followed by the resource.
```
The format: add_new_resource $resource_type (string)  $resource_name (string) $resource_id (int) $capacity (int) $num_of_supported_functionality (int) $DVFS_mode (string)
    $functionality_name (string) $execution_time (float)
        opp $frequency (int - MHz) $voltage (int - mV), defines the Operating Performance Points (OPPs) with frequency and voltage tuples
        trip_freq $trip_1 $trip_2 $trip_3 ..., defines the frequencies that are set at each trip point if throttling is enabled. "-1" means that the frequency is not modified
        power_profile $frequency $power_1 $power_2 $power_3 ... $power_max_capacity
        PG_profile $frequency $power_1 $power_2 $power_3 ... $power_max_capacity
```

Example: The following lines add a new CPU with name=P1, ID=0, capacity=1 and that can run 3 different tasks using "performance" DVFS mode
```
add_new_resource resource_type CPU resource_name P1 resource_ID 0 capacity 1 num_supported_functionalities 3 DVFS_mode performance
opp 1000 1150
trip_freq -1 -1 -1
power_profile 1000 0.1
PG_profile 1000 0.1
scrambler 12
reed_solomon_encoder 15
bpsk_modulation 18
```

## 2.3 Simulator Configuration File
Adjust the configurations in config_file.ini as needed. Here you select the task and resource files, schedulers and which trace files should be created. There are examples of different configuration files in the config_Files folder. 

## 2.4 Running the Simulator
Finally, run DASH_Sim_v0.py to start the simulation. The traces are created in the root folder (where DASH_Sim_v0.py is located) The name of the traces are described in the config_file.ini
Please be sure that all the files listed below are in your file directory.

# 3. File Structure
```
├── DASH_Sim_v0.py               : This file is the main() function which should be run to get the simulation results.
│   ├── clusters.py              : This file contains the information about the clusters in the SoC.
│   ├── common.py                : This file contains all the common parameters used in DASH_Sim.
│   ├── config_file.ini          : This file contains all the file names and variables to initialize the DASH_Sim
│   ├── CP_models.ini            : This file contains the code for dynamic scheduling with Constraint Programming.
│   ├── DASH_Sim_core.py         : This file contains the simulation core that handles the simulation events.
│   ├── DASH_Sim_utils.py        : This file contains functions that are used by DASH_Sim.
│   ├── DASH_SoC_parser.py       : This file contains the code to parse DASH-SoC given in config_file.ini file.
│   ├── DTPM.py                  : This file contains the code for the DTPM module.
│   ├── DTPM_policies.py         : This file contains the DVFS policies.
│   ├── DTPM_power_models.py     : This file contains functions that are used by the DVFS mechanism and PEs to get performance, power, and thermal values.
│   ├── job_generator.py         : This file contains the code for the job generator.
│   ├── job_parser.py            : This file contains the code to parse jobs given in config_file.ini file.
│   ├── processing_element.py    : This file contains the process elements and their attributes.
│   ├── scheduler.py             : This file contains the code for scheduler class which contains different types of scheduler.
│   ├── config_SoC/SoC.*.txt     : These files are the configuration files of the Resources available in DASH-SoC.
│   └── config_Jobs/job_*.txt    : These files are the configuration files of the Jobs.
└── ...
```
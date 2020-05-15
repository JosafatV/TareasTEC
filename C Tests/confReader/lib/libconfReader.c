#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* aux_file = "../config/config.aux";

const char* param1 = "ID";
const char* param2 = "val";
const char* param3 = "t";

typedef struct {
    int ID;
    int val;
    int t;
} config_t;

  /** Read the band varibles from a .conf file
 * 
 * const char* conf_path: the path to the conf file
 * returns: a config_t struct with the information in the file
 */
config_t get_config(const char* conf_path){
    config_t conf;
    FILE* file = fopen(conf_path, "r");
    if(file==NULL){
        printf ("Path to config not avaliable. \n");
        exit(EXIT_FAILURE); 
    }
    char line[256];
    char prev[256];
    while (fgets(line, sizeof(line), file)) {
        char* current = strtok (line, "=:");
        //prev={0};
        while (current) {
            if(!strcmp(prev, param1)){
                conf.ID = atoi(current);
            }
            else if(!strcmp(prev, param2)){
                conf.val = atoi(current);
            }
            else if(!strcmp(prev, param3)){
                conf.t = atoi(current);
            }
            // ADD else if statements according to the amount of parameters
            strcpy(prev, current);
            current = strtok (NULL, "=:");
        }
    }
    fclose(file);
    return conf;
} 


void print_config (config_t *conf){
    printf("The configuration file has the next values: \n");
    printf("  Param 1 is: %d \n",  conf->ID);
    printf("  Param 2 is: %d \n",  conf->val);
    printf("  Param 3 is: %d \n",  conf->t);
}

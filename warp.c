#include "headers.h"


void warp_function(char* str){
    char curr_working_directory[MAX_PATH_LEN]; 
    char* token1;
	token1 = strtok(str, " ");
	if(token1!=NULL){
        if(strcmp(token1, "warp") == 0){
            token1 = strtok(NULL, " ");
            if (chdir(token1) == 0) {
                printf("%s\n", getcwd(curr_working_directory, MAX_PATH_LEN));
            } else {
                printf("chdir, No such file or directory\n");
            }
        }
	}
}



#include "headers.h"


void seek(char* str){
    char* token1;
	token1 = strtok(str, " ");
	if(token1!=NULL){
		token1 = strtok(NULL, " ");
        struct dirent *directory_or_files_list;
        DIR *directory_elements = opendir(".");
        while ((directory_or_files_list = readdir(directory_elements)) != NULL){
            if((strcmp(directory_or_files_list->d_name, token1)) == 0){
                printf("Found in the given directory.\n");
            }
        }
        closedir(directory_elements);
	}
}
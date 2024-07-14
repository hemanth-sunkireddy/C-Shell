#include "../headers/main.h"

void peek_function(char* str){
    struct dirent *directory_or_files_list;
    DIR *dr = opendir(".");
    while ((directory_or_files_list = readdir(dr)) != NULL)
            printf("%s\n", directory_or_files_list->d_name);
    closedir(dr);
}
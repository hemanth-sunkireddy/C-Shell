#include "../headers/main.h"

void seek(char *file_or_folder_name)
{
    struct dirent *directory_or_files_list;
    DIR *directory_elements = opendir(".");
    while ((directory_or_files_list = readdir(directory_elements)) != NULL)
    {
        if ((strcmp(directory_or_files_list->d_name, file_or_folder_name)) == 0)
        {
            printf("Found in the given directory.\n");
        }
    }
    closedir(directory_elements);
}
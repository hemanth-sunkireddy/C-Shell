#include "../headers/main.h"

void peek_function(char *path)
{
    if (path != NULL)
    {
        // Read directory entries
        DIR *dir = opendir(path);
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            printf("%s\t", entry->d_name);
        }

        closedir(dir);
    }
    else
    {
        DIR *current = opendir(".");
        struct dirent *entry;
        while ((entry = readdir(current)) != NULL)
        {
            printf("%s\t", entry->d_name);
        }

        closedir(current);
    }
}
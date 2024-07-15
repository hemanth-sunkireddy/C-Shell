#include "../headers/main.h"

void warp_function(char *path, char *current_working_directory)
{

    if (path == NULL || strlen(path) == 0)
    {
        printf("Invalid input: 'warp' requires a directory path\n");
    }

    if (strcmp(path, ".") == 0)
    {
        // Current Directory.
    }
    else if (strcmp(path, "..") == 0)
    {
        // Move to the parent directory
        if (chdir("..") != 0)
        {
            printf("ERROR IN ..");
        }
        strncpy(path, getcwd(NULL, 0), sizeof(path) - 1);
        path[sizeof(path) - 1] = '\0'; // Ensure null termination
    }

    else if (chdir(path) == 0)
    {
        // Store current working directory in OLDPWD
        if (setenv("OLDPWD", current_working_directory, 1) != 0)
        {
            perror("setenv");
        }

        // Update current_working_directory with the new path
        if (getcwd(current_working_directory, MAX_PATH_LEN) == NULL)
        {
            perror("getcwd");
        }

        // Print the full path of the new current working directory
        printf("Current directory: %s\n", current_working_directory);

        return; // Success
    }
    else
    {
        printf("%s path not found", path);
    }
}
#include "../headers/main.h"

int warp_function(char *str, char *current_working_directory)
{
    // Tokenize the input command.
    char *token = strtok(str, " ");

    // Checking if the token is warp
    if (token != NULL && strcmp(token, "warp") == 0)
    {
        // Get the rest of the input string after "warp"
        char *path = strtok(NULL, "\n");

        // Trimming leading whitespace from path
        while (isspace(*path))
        {
            path++;
        }

        // Trimming trailing whitespace from path
        char *end = path + strlen(path) - 1;
        while (end > path && isspace(*end))
        {
            *end-- = '\0';
        }

        if (path == NULL || strlen(path) == 0)
        {
            printf("Invalid input: 'warp' requires a directory path\n");
            return -1;
        }

        // Checking if the path is "-"
        if (strcmp(path, "-") == 0)
        {
            // Attempt to change directory to the previous directory (OLDPWD)
            path = getenv("OLDPWD");
            if (path == NULL)
            {
                printf("chdir: No OLDPWD environment variable set\n");
                return -1;
            }
        }

        // changing directory to the specified path
        if (chdir(path) == 0)
        {
            // Storing current working directory in OLDPWD
            setenv("OLDPWD", getcwd(current_working_directory, MAX_PATH_LEN), 1);
            return 0; // Success
        }
        else
        {
            printf("chdir: No such file or directory: %s\n", path);
            return -1;
        }
    }

    return -1; // Warp command is not present
}
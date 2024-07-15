#include "../headers/main.h"

int peek_function(char *str)
{
    // Tokenize the input command.
    char *token = strtok(str, " ");

    // Checking if the token is peek
    if (token != NULL && strcmp(token, "peek") == 0)
    {
        // Initialize flags
        int show_hidden = 0; // -a flag
        int show_details = 0; // -l flag

        // Get the rest of the input string after "peek"
        char *flags_and_path = strtok(NULL, "\n");

        // If no arguments provided, default to listing current directory
        if (flags_and_path == NULL || strlen(flags_and_path) == 0)
        {
            flags_and_path = ".";
        }

        // Extract flags and path
        char *flags = strtok(flags_and_path, " ");
        char *path = strtok(NULL, " ");

        // Check flags
        while (flags != NULL)
        {
            if (strcmp(flags, "-a") == 0)
            {
                show_hidden = 1; // Set flag to show hidden files
            }
            else if (strcmp(flags, "-l") == 0)
            {
                show_details = 1; // Set flag to show detailed information
            }
            // Move to next flag
            flags = strtok(NULL, " ");
        }

        // Handle special symbols in path
        if (path != NULL)
        {
            if (strcmp(path, "~") == 0)
            {
                // Handle home directory (~)
                path = getenv("HOME");
                if (path == NULL)
                {
                    printf("peek: No HOME environment variable set\n");
                    return -1;
                }
            }
            else if (strcmp(path, "-") == 0)
            {
                // Handle previous directory (-)
                path = getenv("OLDPWD");
                if (path == NULL)
                {
                    printf("peek: No OLDPWD environment variable set\n");
                    return -1;
                }
            }
        }
        else
        {
            path = "."; // Default to current directory if path is not provided
        }

        // Attempt to open the directory
        DIR *dir = opendir(path);
        if (dir == NULL)
        {
            perror("opendir");
            printf("peek: Cannot open directory: %s\n", path);
            return -1;
        }

        // Read directory entries
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            // Skip hidden files unless -a flag is set
            if (!show_hidden && entry->d_name[0] == '.')
            {
                continue;
            }

            // Print file or directory name
            printf("%s", entry->d_name);

            // Print extra information if -l flag is set
            if (show_details)
            {
                printf("\t"); // Separator
                // Implement additional details if needed
            }

            printf("\n");
        }

        closedir(dir);
        return 1; // Successfully executed peek command
    }

    return -1; // Peek command not present
}
#include "../headers/main.h"

void prompt(char *curr_working_directory)
{
    char hostname[MAX_PATH_LEN];
    gethostname(hostname, sizeof(hostname));
    char *username = getlogin();

    // Checking if the current working directory is the home directory
    if (strcmp(curr_working_directory, "/home") == 0)
    {
        printf("%s@%s:~>", username, hostname);
    }
    else
    {
        printf("%s@%s:%s>", username, hostname, curr_working_directory);
    }
}
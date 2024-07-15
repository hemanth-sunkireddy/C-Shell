#include "../headers/main.h"

// Add commands to history file
void add_to_history(char *command)
{
    FILE *fp = fopen("pastevents.txt", "a");
    if (fp == NULL)
    {
        perror("Error opening history file");
        return;
    }

    fprintf(fp, "%s\n", command);
    fclose(fp);
}

void execute_purge()
{

    FILE *fp = fopen("pastevents.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening pastevents.txt for purge");
        return;
    }
    fclose(fp);
    printf("Past events history purged.\n");
}

int pastevent_function(char *str)
{
    printf("STRING INITIAL: %s", str);
    // Tokenize the input command.
    char *token = strtok(str, " ");
    printf("TOKEN: %s\n", token);
    // Checking if the token is peek
    if (token != NULL && strcmp(token, "pastevents") == 0)
    {
        printf("STRING: %s", str);
        int purge_check = strcmp(str, "purge");
        if(purge_check == 0){
            printf("PURGE FOUND");
            return 1; 
        }
        return 1; // Successfully executed pastevents command
    }

    return -1; // pastevents command not present
}
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

void pastevent_function(char *detail)
{
    FILE *file = fopen("pastevents.txt", "r+");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    // Empty: Print file content.
    if (detail == NULL || strlen(detail) == 0 || strcmp(detail, "") == 0)
    {
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }
        fclose(file);
        return;
    }
}

#include "headers/main.h"
void trimSpaces(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    int index = 0; // Index for modifying the string

    // Trim leading spaces
    while (isspace((unsigned char)str[start]))
    {
        start++;
    }

    // Collapse consecutive spaces into a single space
    for (int i = start; i <= end; i++)
    {
        if (isspace((unsigned char)str[i]))
        {
            // Skip consecutive spaces
            while (isspace((unsigned char)str[i + 1]))
            {
                i++;
            }
            str[index++] = ' '; // Replace consecutive spaces with a single space
        }
        else
        {
            str[index++] = str[i];
        }
    }

    str[index] = '\0';

    // Trim trailing spaces
    while (index > 0 && isspace((unsigned char)str[index - 1]))
    {
        str[--index] = '\0';
    }
}

int main()
{
    char commands_list[MAX_COMMANDS][MAX_TOKEN_LEN]; // Array of Commands entered in a single input.
    int num_tokens = 0;
    char current_working_directory[MAX_PATH_LEN];

    // Initialize current_working_directory with the current path
    if (getcwd(current_working_directory, sizeof(current_working_directory)) == NULL)
    {
        perror("getcwd");
        return 1;
    }

    while (1)
    {
        prompt(current_working_directory); // Display prompt with current working directory

        char input[MAX_PATH_LEN];
        fgets(input, MAX_PATH_LEN, stdin);

        // Reset input count.
        num_tokens = 0;

        tokens_function(input, commands_list, &num_tokens);

        // Processing inputs.
        for (int i = 0; i < num_tokens; ++i)
        {
            trimSpaces(commands_list[i]);
            add_to_history(commands_list[i]);

            // Tokenize the input command.
            char *command = strtok(commands_list[i], " ");
            char *detail = strtok(NULL, "\n");
            if (strcmp(command, "warp") == 0)
            {
                warp_function(detail, current_working_directory);
                if (getcwd(current_working_directory, sizeof(current_working_directory)) == NULL)
                {
                    perror("getcwd");
                    return 1;
                }
            }
        }
    }

    return 0;
}
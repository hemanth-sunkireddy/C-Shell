#include "headers/main.h"

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
            // Call warp_function to process each command
            if (warp_function(commands_list[i], current_working_directory) == 0)
            {
                // If warp_function succeeded, update the prompt with the new current directory
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
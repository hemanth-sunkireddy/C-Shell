#include "headers.h"

int main()
{
    while (1)
    {
        prompt();
        char current_working_directory[MAX_PATH_LEN];
        char input[MAX_PATH_LEN];
        fgets(input, MAX_PATH_LEN, stdin);
        tokens_function(input);
    }
    return 0;
}

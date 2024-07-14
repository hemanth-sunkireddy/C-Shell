#include "headers/main.h"

int main() {
    char commands_list[MAX_COMMANDS][MAX_TOKEN_LEN]; // Array of Commands entered in a single input.
    int num_tokens = 0;
    
    while (1) {
        prompt();
        char input[MAX_PATH_LEN];
        fgets(input, MAX_PATH_LEN, stdin);

        // Reset input count.
        num_tokens = 0;
        
        tokens_function(input, commands_list, &num_tokens);
        
        // Processing inputs.
        for (int i = 0; i < num_tokens; ++i) {
            printf("Token %d: %s\n", i + 1, commands_list[i]);
        }
    }
    
    return 0;
}
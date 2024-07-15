#include "../headers/main.h"

void tokens_function(char *str, char subtoks[MAX_COMMANDS][MAX_TOKEN_LEN], int *num_tokens)
{
    *num_tokens = 0;

    char *token1;
    char *token2;
    char *tok = strtok_r(str, ";", &token1);

    while (tok != NULL && *num_tokens < MAX_COMMANDS)
    {
        char *subtok = strtok_r(tok, "&", &token2);

        while (subtok != NULL)
        {
            if (*num_tokens < MAX_COMMANDS)
            {
                if (*num_tokens < MAX_COMMANDS && subtok[0] != '\0' && strcmp(subtok, "\n") != 0)
                {
                    strcpy(subtoks[*num_tokens], subtok);
                    (*num_tokens)++;
                }
            }
            else
            {
                fprintf(stderr, "Exceeded maximum number of tokens\n");
                return;
            }
            subtok = strtok_r(NULL, "&", &token2);
        }

        tok = strtok_r(NULL, ";", &token1);
    }
}
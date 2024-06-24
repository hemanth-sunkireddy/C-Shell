#include "headers.h"

void tokens_function(char* str){
	int length = strlen(str);
	str[length-1] = '\0';
	char* token1;
    char* token2;
    char* tok = strtok_r(str, ";", &token1);
    while (tok != NULL) {
        // system_commands(tok);
        // seek(tok);
        char* subtok = strtok_r(tok, "&", &token2);
        if(strcmp(subtok, "peek") == 0){
            peek_function(subtok);
        }
        while (subtok != NULL) {
            warp_function(subtok);
            // proclore();
            pastevent_function(subtok);
            subtok = strtok_r(NULL, "&", &token2);
        }
        tok = strtok_r(NULL, ";", &token1);
    }
}
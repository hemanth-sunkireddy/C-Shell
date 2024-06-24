#include "headers.h"

void prompt() {
    char hostname[MAX_PATH_LEN];
    char curr_working_directory[MAX_PATH_LEN];
    gethostname(hostname, sizeof(hostname));
    char *username = getlogin();
    getcwd(curr_working_directory, 4096);
    if( strcmp(curr_working_directory, "/home") == 0 ){
        printf("%s@%s:~>", hostname, username);    
    }
    else{
        printf("%s@%s:%s>", hostname, username, curr_working_directory);
    }
}


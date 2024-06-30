#include "../headers.h"

void proclore(){
    int pid_value = getpid();
    char pid_variable[6];
    sprintf(pid_variable,"%d",pid_value);
    char proc_variable[14] = "/proc/";
    strcat(proc_variable, pid_variable);
    char status_variable[25] = "/status";
    strcat(proc_variable, status_variable);
    printf("%s\n", proc_variable);
    char cat_variable[32] = "cat "; 
    strcat(cat_variable, proc_variable);
    printf("%s\n", cat_variable);
    system(cat_variable);
}
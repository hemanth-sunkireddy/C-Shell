#include "../headers.h"

void pastevent_function(char* str){
    FILE *fp;
    fp = fopen("pastevents.txt" , "a");
    fprintf(fp, "%s\n", str);
    fclose(fp);
}
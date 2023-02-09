#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslog.h>
#include <syslog.h>

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Need two commandline arguments\n");
        syslog(LOG_ERR,"Need two commandline arguments\n" );
        exit(1);
    }
    char* writefile =  argv[1];
    char* writestr =  argv[2];

    openlog(NULL, 0, LOG_USER);
    FILE* fptr =  fopen(writefile, "w");
    if(fptr == NULL) {
        //printf("Error opening file %s for writting\n", writefile);
        syslog(LOG_ERR, "Error opening file %s for writting\n", writefile);
        exit(1);
    }
    fprintf(fptr, "%s", writestr);
    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr,writefile);
    fclose(fptr);

    return 0;
}

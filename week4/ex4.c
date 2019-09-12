#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <fcntl.h> 
#include <sys/wait.h>

#define true 1
#define false 0
#define MAX_LINE 1024

int main(){
    char s[MAX_LINE];
    char *argv[128];

    while (true) {
        // shell prompt
        printf("¯\\_(ツ)_/¯ > ");

        // read line
        fgets(s, MAX_LINE, stdin);
        
        // read program name/path
        argv[0] = strtok(s, " \n");

        // read args
        int argc = 1, background = false, childPid, status;
        while ((argv[argc++] = strtok(NULL, " \n"))) {
        }
        argc--;
        printf("%s;%s;%s;\n", argv[0], argv[1], argv[2]);

        // handle background
        if ((strcmp(argv[argc - 1], "&") == 0)) {
            background = true;
            argc--;
        }
    
        // put args NULL terminator
        argv[argc] = NULL;

        if ((childPid = fork()) == false) { // handle chilf fork
            // hide stdout and stderr of a background process
            if (background) {
                int fd = open("/dev/null", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

                dup2(fd, 1);
                dup2(fd, 2);

                close(fd);
            }

            int error = execvp(argv[0], argv);
            if (error) {
                printf("Failed to start child process, error code: %d\n", error);
            }
            return error;
        } else if(background) { // handle parent
            printf("Background process id: %d\n", childPid);
        } else {
            waitpid(childPid, &status, 0);
            printf("Exit code: %d\n", status);
        }
    }
    return 0;
}

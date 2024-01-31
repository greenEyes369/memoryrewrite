#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ptrace.h>

int main() {
    pid_t pid = fork();
    void* addr;
    int status;

    if (pid == -1) {
        printf("Fork failed: %d\n", errno);
    }
    else if (pid == 0) {
/*        printf("Starting ptrace call\n");
        printf("...\n");

        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
*/
        char cmd[] = "./clock";

        char * argVec[] = {"clock", NULL};
        char * envVec[] = {NULL};

        printf("Starting execve call %s:\n", cmd);
        printf("...\n");

        if(execve(cmd, argVec, envVec) == -1) {
            perror("Could not execute execve.\n");
        }
        printf("Something went wrong...\n");
    }
    else {
        scanf("%i", addr);

        ptrace(PTRACE_ATTACH, pid, NULL, NULL);

        while(ptrace(PT_READ_D, pid, addr, NULL) % 5 == 0){
            ptrace(PTRACE_POKEDATA, pid, addr, 5);
        }
    }
}
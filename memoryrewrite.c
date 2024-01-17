#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ptrace.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Fork failed: %d\n", errno);
    }
    else if (pid == 0) {
        char cmd[] = "./clock";

        char * argVec[] = {"clock", NULL};
        char * envVec[] = {NULL};

        printf("Starting execve call %s:\n", cmd);
        printf("...\n");

        if(execve(cmd, argVec, envVec) == -1) {
            perror("Could not execute execve.\n");
        }
        printf("Something went wrong...\n");

        return 0;
    }
    else {
        return 0;
    }
}
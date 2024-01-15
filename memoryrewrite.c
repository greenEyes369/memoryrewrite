#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Fork failed: %d\n", errno);
    }
    else if (pid == 0) {

    }
    else {

    }
}
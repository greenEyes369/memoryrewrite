#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 0;
    printf("Memory address of x: %p\n", (void *)&x);
    while(x != 25) {
        sleep(10);
        x = x + 5;
        printf("%d\n", x);
    }
    return 0;
}
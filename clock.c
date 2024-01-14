#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 0;
    while(x != 25) {
        sleep(1);
        x = x + 5;
        printf("%d\n", x);
    }
}
#include <stdlib.h>
#include <stdio.h>

void makeStair(int steps) {
    for (int step = 1; step <= steps; step++) {
        for (int space = 1; space <= steps - step; space++) {
            printf(" ");
        }
        for (int hash = 1; hash <= step; hash++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {

    int times;

    scanf("%d", &times);
    makeStair(times);

    system("PAUSE");
    return 0;
}

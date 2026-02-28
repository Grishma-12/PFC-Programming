#include <stdio.h>

int main(void) {
    for (int i = 0; i < 10; i++) {
        printf("Welcome to C Programming!\n");
    }

    printf("\nWith counter:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d: Welcome to C Programming!\n", i);
    }

    return 0;
}

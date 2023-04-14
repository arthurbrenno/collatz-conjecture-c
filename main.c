#include <stdio.h>
#include <stdlib.h>

void step(int* number);

int main(int argc, char* argv[]) {
    int numberOfSteps = 0;
    char buffer[100];
    int number;

    printf("Collatz Conjecture\n\nEnter a number: ");
    fgets(buffer, sizeof(buffer), stdin);
    number = atoi(buffer);

    if (number <= 1) {
        return 0;
    }
    printf("Calculating...\n");
    while(number > 1) {
        step(&number);
        numberOfSteps++;
    }
    printf("%d", number);
    getchar();
    return 1;
}

void step(int* number) {
    if(*number % 2 == 0) {
        printf("[n/2]\n");
        *number>>=1;
        return;
    }
    printf("[3n + 1]\n");
    *number = (*number * 3) + 1;
}
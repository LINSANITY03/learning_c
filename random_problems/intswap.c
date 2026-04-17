#include <stdio.h>

void swap(int *num1, int *num2); // function declaration

int main() {
    int i = 10, j = 20;

    swap(&i, &j); // pass addresses

    printf("%d\n", i);
    printf("%d\n", j);

    return 0;
}

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
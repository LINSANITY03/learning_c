#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *p = malloc(10 * sizeof(int));

    for (size_t i = 0; i < 10; i++){
        p[i] = i * 2;
    }

    printf("third number: %d\n", p[2]);
    free(p);
    p = NULL;
    printf("first number: %d\n", p[0]);
    return 0;
}
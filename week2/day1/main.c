/*
we learned about lldb for mac.

- setting the breakpoint at main and run
b main
run

- instead of stepping over each iteration manually 
n
n
- we can use the following code to step over 10 iteration
b 10
continue

- after the loop we can inspect memory.
memory read -f d -c 10 p

- even after free the pointer shows same memory address if not set null.
p p

- use backtrace to inspect the problem.
bt
*/
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
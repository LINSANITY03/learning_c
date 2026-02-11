#include<stdio.h>

int main(void){
    // set a array
    int a[5] = {1, 2, 3, 4, 5};
    printf("First number: %d\n", a[0]);
    
    // set a pointer
    int *p = a;
    printf("First point value: %d\n", p[0]);
    printf("First value: %d\n", *p);
    printf("Second value: %d\n", *(p+2));
    printf("Second value: %d\n", p[2]);

    int *s = &a[0];
    printf("Pointer value: %d\n", *s);

    printf("Size of array: %zu\n", sizeof(a)); // 20
    // because array a has 5 int and 1 int is 4 bytes hence 4*5= 20 bytes

    printf("Size of pointer: %zu\n", sizeof(s));     // 8 bytes (64-bit) depends on the architecture
    printf("Size of *s: %zu\n", sizeof(*s)); // 4 bytes per one value which is int

    int (*h)[5] = &a;
    printf("Size of *h: %zu\n", sizeof(*h));
    printf("Array via pointer to array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", (*h)[i]);
    }
    printf("\n");


    // ------------ points to remember ------------ //
    /* 
        x[y]  ≡  *(x + y) address + offset → dereference
        p[2]  == *(p + 2) pointer arithmetic.

        1. a[0] — data-focused, readable
            - You are working with arrays
            - You care about position
            - You want readability
        
        2. *p — pointer-focused
            - You are iterating
            - You are walking memory
            - You’re writing low-level or performance code
        
        3. p[i] — hybrid (most common in real code)
            - Pointer came from a function
            - Array size is unknown
            - You want array-like syntax on dynamic memory
        
        4. *(p + i) — explicit memory math
            - Teaching
            - Debugging
            - Writing very low-level code
            - Showing intent clearly

    */
    return 0;
}
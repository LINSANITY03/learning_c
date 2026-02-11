#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    int *numbers = malloc(10 * sizeof(int));
    // If you don’t free(numbers), that memory is still technically allocated — this is called a memory leak.

    for (int i = 0; i < 10; i++) {
        numbers[i] = i * 2;
    }

    printf("First number: %d\n", numbers[0]);
    printf("Numbers %d\n", *numbers);
    /*
        Numbers prints the value stored in the pointer
        The value is a memory stored in heap

    */
    // BUG: memory is never freed

    free(numbers);
    numbers = NULL; // defensive, not magic
    printf("%d\n", numbers == NULL);

    return 0;
}
/*
Stack: (variables that disappear when function ends)
+-----------+
| numbers   | ---->  Heap: (10 contiguous boxes)
+-----------+       +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
                     |     |     |     |     |     |     |     |     |     |     |
                     +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
                     indexes: 0     1     2     3     4     5     6     7     8     9
*/
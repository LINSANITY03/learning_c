#include<stdio.h>
#include<stddef.h>
/*
    Padding is added between members or at the end of the struct so that the size of the struct 
    is a multiple of the largest alignment requirement among its members.
*/
struct MyStruct {
    char c; // 1 byte + 7 bytes padding
    double d; // 8 bytes
    int i; // 4 bytes + 4 bytes padding
};

/*
    Modern CPUs fetch memory in cache lines (commonly 64 bytes).
    Padding can cause false sharing if structs are badly aligned or too large.
    Reordering struct fields can reduce size and improve cache efficiency.
    Hence,
    By ordering from largest → smallest, padding is minimized.

    Explanation:
    Currently, d+i+c = 8 + 4 + 1 = 13 bytes
    The compiler adds padding at the end so that the struct size is a multiple of 8 → 3 bytes padding
    Final sizeof(MyStructOptimized) = 16 bytes

    Visual:
    Address:   0 1 2 3 4 5 6 7 | 8 9 10 11 | 12 13 14 15
    Member:    d d d d d d d d | i i  i  i | c -  -  -

*/
struct MyStructOptimized {
    double d; // 8 bytes
    int i; // 4 bytes
    char c; // 1 byte + 3 bytes
};

int main(){
    printf("size of struct MyStruct %zu\n", sizeof(struct MyStruct)); // 24
    printf("Offset of c: %zu\n", offsetof(struct MyStruct, c)); // 0
    printf("Offset of d: %zu\n", offsetof(struct MyStruct, d)); // 8
    printf("Offset of i: %zu\n", offsetof(struct MyStruct, i)); // 16

    printf("------------------------------------------------------\n");
    printf("size of struct MyStructOptimized %zu\n", sizeof(struct MyStructOptimized)); // 16
    printf("Offset of c: %zu\n", offsetof(struct MyStructOptimized, c)); // 12
    printf("Offset of d: %zu\n", offsetof(struct MyStructOptimized, d)); // 0
    printf("Offset of i: %zu\n", offsetof(struct MyStructOptimized, i)); // 8
    return 0;
}

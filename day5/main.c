#include<stdio.h>

void func3(){
    int c;
    printf("func3 stack address: %p\n", (void*)&c);
}

void func2(){
    int b;
    printf("func2 stack address: %p\n", (void*)&b);
    func3();
}

/*
    Every datatype has its own pointer types to represent a memory address
    &a is already a pointer
    (void*)&x  // same address, just re-labeled as generic
    Only when we want to print the memory address.
    Casting does not change the address — it only changes how C treats it.
*/
void func1(){
    int a;
    printf("func1 stack address: %p\n", (void*)&a);
    func2();
}

// int main(){
//     int main_var;
//     printf("main stack address: %p\n", (void*)&main_var);
//     func1();
//     return 0;
// }

/*
    Output:
    main stack address: 0x16d3becd8
    func1 stack address: 0x16d3becac
    func2 stack address: 0x16d3bec8c
    func3 stack address: 0x16d3bec6c

    Each function call pushed a new stack frame
    Addresses are decreasing as we go deeper
    Difference is roughly constant (frame size + alignment)
*/

void recurse(int depth){
    int x;
    printf("Depth %d, address: %p\n", depth, (void*)&x);
    printf("Depth %d, memory-address: %p\n", depth, &x);
    recurse(depth + 1);
}

// int main(){
//     recurse(1);
//     return 0;
// }

void boom(){
    int big_array[100000];
    printf("Stack address %p\n", (void*)&big_array);
    boom();
}

int main(){
    boom();
    return 0;
}
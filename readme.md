# Basics 

1. **Variable**
    - `int x = 10;`
    - C creates a box named x and store the value 10. The box is stored in some address.

2. **The address of operator &**
    - `&x` - Where does `x` live in memory.
    - It returns an address and the type cast is `int*`. So, `int *p=&x`.

3. **What `int *p` actually means**
    - It means p is a variable that can store the address of an int.

4. **The dereference operator `*`**
    - `*p` means go to the address stored in `p` and give me the value there.

Example:
```
    int x = 10;
    int *p = &x;

    printf("%d\n", *p); // 10
```

5. **`p` vs `*p` vs `&p`
- `p`is the address of `x`.
- `*p` is the value stored in address `p`.
- `&p` is the address of the pointer variable itself

## Why use pointer at all, why not shallow copy variable?
1. Without pointer functions get copies.
2. Avoid copying big data (performance + memory).
3. Shared state (multiple names -> same data).
4. Dynamic memory (data that lives beyond scope).
    - Memory created at runtime.
    - No variable name.
    - Only reachable via pointer.

## Day 2 — Heap & Ownership (This Is Where People Wash Out)

If Day 1 was “how a program runs”, Day 2 is where you learn responsibility.

In C:
If you allocate it, you own it
If you own it, you free it
If you free it twice, you’re wrong
If you touch it after freeing, you’re wrong
The compiler will not save you
The OS will not warn you
Production will crash silently

<br>

## Core Mental Model (Non-Negotiable)

### Stack
- Automatic
- Scoped
- Fast
- Safe-ish

### Heap
- Manual
- Long-lived
- Dangerous
- Requires discipline

Heap bugs don’t fail immediately.
They corrupt reality and explode later.
That’s why seniors fear them.

<br>

## malloc / calloc / free

### malloc(size)
- Gives you raw bytes
- Contents = garbage
- You must initialize if needed

### calloc(n, size)
- Allocates + zeroes memory
- Slightly slower
- Safer for beginners

### free(ptr)
- Returns memory to allocator
- Does NOT set pointer to NULL
- Using ptr after this is undefined behavior

** This are all created with the help of chatgpt **
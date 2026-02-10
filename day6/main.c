#include<stdio.h>
#include <stdlib.h>
#include<stddef.h>

// typedef just gives a new name to a type.
typedef struct{
    int *data;
    size_t len;
    size_t cap;
} Vec;

/*
    API

    void  vec_init(Vec *v);
    void  vec_push(Vec *v, int value);
    int   vec_get(const Vec *v, size_t index);
    void  vec_resize(Vec *v, size_t new_cap);
    void  vec_free(Vec *v);

*/

/*
    struct Vector v;
    v.data;        // dot

    struct Vector *vp;
    vp->data;      // arrow
*/
void vec_init(Vec *v){
    v->data = NULL;
    v->len = 0;
    v->cap = 0;
}

void vec_resize(Vec *v, size_t new_cap){
    if (new_cap == 0){
        v->data = NULL;
        v->len = 0;
        v->cap = 0;
        return;
    }

    int *new_data = realloc(v->data, new_cap * sizeof(int));
    if (!new_data){
        // realloc failed → old data still valid
        return;
    }

    v->data = new_data;
    v->cap = new_cap;

    if (v->len > v->cap){
        v->len = v->cap;
    }
}

void vec_push(Vec *v, int value){
    // Passing by value (Vec v) would copy it.
    if (v->len == v->cap){
        size_t new_cap = (v->cap == 0) ? 4 : v->cap * 2;
        vec_resize(v, new_cap);
    }
    v->data[v->len++] = value; // uses current len and increase after assignment
}

int vec_get(const Vec *v, size_t index){
    if (index >= v->len){
        fprintf(stderr, "No value at this index\n");
        return 0;
    }
    return v->data[index];
}

void vec_free(Vec *v){
    free(v->data);
    v->data = NULL;
    v->len = 0;
    v->cap = 0;
}

int main(void){
    Vec v;
    vec_init(&v);
    
    for(int i = 0; i < 10; i++){
        vec_push(&v, i);
    }

    puts("Getting the value from data:\n");
    for (size_t i = 0; i < v.len; i++) {
        printf("%d\n", vec_get(&v, i));
    }

    vec_get(&v, 100);

    printf("Elements used: %zu\n", v.len);
    printf("Capacity: %zu\n", v.cap);
    printf("Memory allocated (bytes): %zu\n", v.cap * sizeof(int));
    printf("size of indiviual slot in data:%zu\n", sizeof(v.data));
    return 0;
}
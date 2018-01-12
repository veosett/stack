#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdbool.h>

typedef struct {
    size_t length;
    size_t elemSize;
    size_t logLenght;
    void* elems;
    void (*DeleteString)(void* elem);

} Stack;

void NewStack(Stack *s, size_t elemSize, size_t length, void (*DeleteString)(void* elem));
int PushStack(Stack *s, void *elemAddr);
int PopStack(Stack* s);

bool IsEmpty(Stack *s);
void DeleteString(void* elem);
void DeleteStack(Stack *s);


#endif //STACK_STACK_H

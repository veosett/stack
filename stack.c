#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <memory.h>

void NewStack(Stack *s, size_t elemSize, size_t length) {
    s->length = length;
    s->elemSize = elemSize;
    s->logLenght = 0;
    s->elems = malloc(elemSize * length);
    assert(s->elems != NULL);
}

int PushStack(Stack* s, void* elemAddr) {
    if (s->length == s->logLenght) {
        s->length *= 2;
        s->elems = realloc(s->elems, s->length);
    }
    void* logElem = (char*)s->elems + s->elemSize * s->logLenght;
    memcpy(logElem, elemAddr, s->logLenght);
    s->logLenght++;

    return 0;
}

int PopStack(Stack *s) {
    if (IsEmpty(s)) {
        return -1;
    }

    s->logLenght--;
    return 0;
}

bool IsEmpty(Stack *s) {
    return s->logLenght == 0;
}

void DeleteStack(Stack *s) {
    free(s->elems);
}

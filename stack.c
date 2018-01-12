#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <memory.h>

void NewStack(Stack *s, size_t elemSize, size_t length, void (*DeleteString)(void *elem)) {
    if (DeleteString != NULL) {
        s->DeleteString = DeleteString;
    } else {
        s->DeleteString = NULL;
    }
    s->length = length;
    s->elemSize = elemSize;
    s->logLenght = 0;
    s->elems = malloc(16);
    assert(s->elems != NULL);
}

int PushStack(Stack *s, void *elemAddr) {
    if (s->length == s->logLenght) {
        s->length *= 2;
        s->elems = realloc(s->elems, s->length * s->elemSize);
        assert(s->elems != NULL);
    }
    void *logElem = (char *) s->elems + s->elemSize * s->logLenght;
    memcpy(logElem, elemAddr, s->elemSize);
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
void DeleteString(void* elem) {
    free(elem);
}

void DeleteStack(Stack *s) {
    if (s->DeleteString != NULL) {
        for (int i = 0; i < s->logLenght; i++) {
            void* elem = (char*)s->elems + i * s->elemSize;
            s->DeleteString(elem);
        }
    }
    free(s->elems);
}

#include <stdio.h>
#include "string.h"
#include "stack.h"

int main() {

    const char* arr[] = {"first", "second", "third"};
    Stack s;
    NewStack(&s, sizeof(int), 4, DeleteString);

    for (int i = 0; i < 3; i++) {
        void * str = strdup(arr[i]);
        PushStack(&s, str);
    }

    DeleteStack(&s);

    return 0;
}
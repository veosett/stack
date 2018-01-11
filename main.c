#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <memory.h>

int main() {

    Stack s;
    int some = 21;
    NewStack(&s, sizeof(int), 8);
    PushStack(&s, &some);
    some = 2;
    PushStack(&s, &some);
    some = 14;
    PushStack(&s, &some);
    PopStack(&s);
    some = 6;
    PushStack(&s,&some);

    DeleteStack(&s);

    printf("Hello, World!\n");
    return 0;
}
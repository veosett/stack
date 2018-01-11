#include <stdio.h>
#include "stack.h"

int main() {

    Stack s;
    int some = 21;
    NewStack(&s, sizeof(int), 4);
    PushStack(&s, &some);
    some = 2;
    PushStack(&s, &some);
    some = 14;
    PushStack(&s, &some);
    some = 6;
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PushStack(&s,&some);
    PopStack(&s);
    PopStack(&s);
    PopStack(&s);
    PopStack(&s);

    DeleteStack(&s);

    return 0;
}
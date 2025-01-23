#include <stdio.h>
#include <stdlib.h>

int *create_stack(int no_items)
{
    int *stack = malloc(sizeof(int) * no_items);

    return stack;
}

void push(int *top, int value)
{
}

int main(void)
{
    int *my_stack = create_stack(5);

    push(&my_stack, 10);

    printf("%p\n", my_stack);

    return 0;
}
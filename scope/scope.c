#include <stdio.h>

/*
1. Write a program that pass a phrase to a function, and the function prints this phrase.
2. Write a program that call a function 10 times, each time this function must display a counter of how many times it was already used.
*/

void display(char str[])
{
    printf("%s\n", str);
}

void function_call(int *count)
{
    (*count)++;
    printf("%d\n", *count);
}

int main(void)
{

    display("Hello World");

    int count = 0;

    function_call(&count);

    function_call(&count);

    return 0;
}
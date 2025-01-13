#include <stdio.h>
#include "calc.c"

int main()
{
    printf("%d\n", calc(2));

    if (pythagoras(3, 4) == 5)
        puts("Program works!");
    else
        puts("Check again");

    return 0;
}
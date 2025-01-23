#include <stdio.h>
#include <math.h>

int calc(int num)
{
    return 14 * num - 15;
}

int square(int num) { return num * num; }

int add(int num1, int num2)
{
    return num1 + num2;
}

int pythagoras(int sideA, int sideB)
{
    int sideC = add(square(sideA), square(sideB));
    return sqrt(sideC);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Exercise 1, In a void function, add two values and then print that value in main​

Exercise 2, Create a function which takes two pointers to integers and swaps the values they are pointing to, without changing the original memory of the two integers​

Exercise 3, Create two pointers to two numbers and swap them ​

Exercise 4, create a program that crashes by trying to modify read only memory

1. Consider a function pointer table with 3 entries.
   Write a function that return a function pointer according to the index received in the parameters.

*/

void add(int num1, int num2, int *sum)
{
    *sum = num1 + num2;
}

void swap_address(int **ptrA, int **ptrB)
{
    // puts("func");
    // printf("Value of A: %d Value of B: %d\n", *ptrA, *ptrB);
    // printf("Address of ptrA: %p Address of ptrB: %p\n", ptrA, ptrB);
    // printf("TEST* Address of ptrA: %p Address of ptrB: %p\n", &ptrA, &ptrB);

    int *temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    // puts("after");
    // printf("Address of ptrA: %p Address of ptrB: %p\n", ptrA, ptrB);
    // printf("Value of A: %d Value of B: %d\n", *ptrA, *ptrB);
}

void swap_value(int *ptrA, int *ptrB)
{
    puts("before");
    printf("Value of A: %d Value of B: %d\n", *ptrA, *ptrB);

    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    puts("after");
    printf("Value of A: %d Value of B: %d\n", *ptrA, *ptrB);
    // printf("Address of ptrA: %p Address of ptrB: %p\n", &ptrA, &ptrB);
}

int main(void)
{

    int a = 1;
    int b = 3;

    int sum = 0;

    add(a, b, &sum);

    // printf("%d\n", sum);

    int *ptr1 = &a;
    int *ptr2 = &b;

    // printf("Main* Address of A: %p Address of B: %p\n", &a, &b);
    // printf("Main* "
    //        "Address of ptrA: %p\n"
    //        "Val of ptrA: %p\n"
    //        "Address of A: %p\n",
    //        &ptr1, ptr1, &a);

    printf("Address of ptrA: %p Address of ptrB: %p\n", ptr1, ptr2);
    swap_address(&ptr1, &ptr2);
    // swap_value(ptr1, ptr2);
    puts("after");
    printf("Address of ptrA: %p Address of ptrB: %p\n", ptr1, ptr2);

    char *test_str = "Test";

    // test_str[0] = 'b';

    return 0;
}
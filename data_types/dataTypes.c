#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1. Write a program which prints the sum of the numbers a, b, and c.
// 2. Write a program that convert a temperature in Celsius to Fahrenheit and Kelvin.
// 3. Write a program to convert a string to an unsigned long integer.

int print_sum(int a, int b, int c)
{
    return a + b + c;
}

int convert_temp(int temp, char choice)
{
    if (choice == 'f')
        return (temp * 1.8) + 32;
    else if (choice == 'k')
        return temp + 273.15;

    return -1;
}

unsigned long str_to_ul(char str[])
{
    char buffer[255];
    // char *buffer = malloc();
    int len = sizeof(buffer) / sizeof(buffer[0]);

    unsigned long x = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        x += str[i];
        // if (val > 47 && val < 58)
        // {
        //     // while (*buffer++);

        //     // *(buffer - 1) = val;

        //     // *buffer = '\0';

        //     printf("%d\n", val);
        // }
    }

    printf("%s\n", buffer);

    return x;
}

int main(void)
{

    printf("Sum: %d\n", print_sum(1, 2, 3));

    printf("Temperature: %d\n", convert_temp(0, 'k'));

    printf("%lu\n", str_to_ul("abc"));

    return 0;
}
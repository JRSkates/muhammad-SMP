#include <stdio.h>

/*
1. Write a program where you have 2 variables (A and B) initialised as zero, this program should iterate 20 times,
in each iteration you should increment "A" by 3 and "B" by 7. The program should print the current values every 5
iterations and the last values, besides that, the program should print A if it is an odd number, and print B if it is an even number.
2. What is the output of the code below? Could you explain your answer?
        #include <stdio.h>

        int main(void)
        {
        unsigned int    A = -10;
        int             B = 5;
        unsigned int    C = 100;

        if(A > B)
        {
            printf("A > B\n");
        }
        else
        {
            printf("B > A\n");
        }


        if(A > C)
        {
            printf("A > C\n");
        }
        else
        {
            printf("C > A\n");
        }


        if(B > C)
        {
            printf("B > C\n");
        }
        else
        {
            printf("C > B\n");
        }

        return 0;
*/

/*
Answer to Question 2.
1.
*/

int main(void)
{

    // int A = 0;
    // int B = 0;

    // for (int i = 0; i < 20; i++)
    // {
    //     if (i % 5 == 0)
    //         printf("A: %d, B: %d\n", A, B);

    //     if (A % 2 == 1)
    //         printf("A: %d\n", A);

    //     if (B % 2 == 0)
    //         printf("B: %d\n", B);

    //     A += 3;
    //     B += 7;
    // }

    unsigned int A = -10;
    int B = 5;
    unsigned int C = 100;

    if (A > B)
    {
        printf("A > B\n");
    }
    else
    {
        printf("B > A\n");
    }

    if (A > C)
    {
        printf("A > C\n");
    }
    else
    {
        printf("C > A\n");
    }

    if (B > C)
    {
        printf("B > C\n");
    }
    else
    {
        printf("C > B\n");
    }

    printf("%u\n", A);

    return 0;
}
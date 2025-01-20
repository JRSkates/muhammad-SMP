#include <stdio.h>
#include <string.h>

int main(void)
{

    char string[12] = "Hello World";
    int word_count = 0;

    int len = strlen(string);

    // 1. Write a program to print individual characters of a string in reverse order.
    puts("---------------------");
    puts("Exercise 1:");

    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }

    // 2. Write a program to count the total number of words in a string.
    puts("\n---------------------");
    puts("Exercise 2:");

    char str[] = " This  -is,a.string . ";
    char delim[] = " ,;.-";

    char *tok = strtok(str, delim);

    while (tok != NULL)
    {
        word_count++;
        printf("%s\n", tok);
        tok = strtok(NULL, delim);
    }

    printf("Word Count: %d\n", word_count);

    // 3. Write a program that counts the number of times a word is in a phrase.
    puts("---------------------");
    puts("Exercise 3:");

    char ex3[] = "The cat in the hat at\0";
    char match[] = "t";
    int match_count = 0;

    char *ex3_tok = ex3;

    if (ex3[strlen(ex3)] != '\0')
        return 1;

    while ((ex3_tok = strstr(ex3_tok, match)) != NULL)
    {

        match_count++;
        // printf("%s\n", ex3_tok);
        ex3_tok++;
    }

    printf("Match Count: %d\n", match_count);

    // 4. Write a program to sort a string array in ascending order. + Bubble Sort
    puts("---------------------");
    puts("Exercise 4:");

    char ex4[] = {'h', 'e', 'l', 'l', 'o'};

    for (int i = 0; i < strlen(ex4) - 1; i++)
    {
        for (int j = i; j < strlen(ex4) - 1; j++)
        {
            if (ex4[j] > ex4[j + 1])
            {
                ex4[j] = ex4[j] ^ ex4[j + 1];
                ex4[j + 1] = ex4[j] ^ ex4[j + 1];
                ex4[j] = ex4[j] ^ ex4[j + 1];
            }
        }
    }

    for (int i = 0; i < strlen(ex4); i++)
    {
        printf("%c ", ex4[i]);
    }
    puts("---------------------");

    return 0;
}
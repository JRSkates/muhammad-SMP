#include <stdio.h>

/*
1. Write a program which prints a string previously stored in a char array.
2. Write a program which prints all the values stored in a struct.
3. Consider that a 2 bytes variable Prot is composed of 3 fields (Type, Priority and ID) as shown below.
   Write a program that prints the values of of these 3 fields (Type, Priority and ID) if Prot = 0xB7B2.
*/

struct User
{
    char name[20];
    int age;
};

// void display_user()

int main(void)
{
    char str[7] = {'F', 'o', 'o', 'B', 'a', 'r'};

    str[6] = '\0';

    printf("%s\n", str);

    struct User user1 = {"Test User", 20};

    printf("Name: %s, Age: %d\n", user1.name, user1.age);

    return 0;
}
#include <stdio.h>

/*
1. Write a program which prints a string previously stored in a char array.
2. Write a program which prints all the values stored in a struct.
3. Consider that a 2 bytes variable Prot is composed of 3 fields (Type, Priority and ID) as shown below.
   Write a program that prints the values of of these 3 fields (Type, Priority and ID) if Prot = 0xB7B2.
Type	Priority	ID
6 bits	3 bits	    7 bits

*/

struct User
{
    char name[20];
    int age;
};

union data
{
    u_int16_t val;
    struct
    {
        unsigned short id : 7;
        unsigned short priority : 3;
        unsigned short type : 6;
    } fields;
};

// void display_user()

int main(void)
{
    char str[7] = {'F', 'o', 'o', 'B', 'a', 'r'};

    str[6] = '\0';

    printf("%s\n", str);

    struct User user1 = {"Test User", 20};

    printf("Name: %s, Age: %d\n", user1.name, user1.age);

    int Prot = 0xB7B2;

    union data data1;

    data1.val = 0xB7B2;

    printf("Type: %u\n", data1.fields.type);
    printf("Priority: %u\n", data1.fields.priority);
    printf("Id: %u\n", data1.fields.id);

    return 0;
}
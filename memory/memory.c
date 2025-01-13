#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_sky_team(void)
{
    char skyName[10];
    char *pTeamName = (char *)malloc(10);

    strcpy(skyName, "Sky UK");
    strcpy(pTeamName, "Home Comms SW Team");

    // print team name
    printf("%s: %s\n", skyName, pTeamName);

    // Memory was not freed
    free(pTeamName);
}

int main(void)
{

    print_sky_team();

    return 0;
}
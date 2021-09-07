#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readString(char inputArr[])
{
    char letter;
    int index = 0, length;

    // reads first letter of input
    scanf("%c", &letter);

    // scanf for each character (better than using fgets)
    while (letter != '\n')
    {
        inputArr[index] = letter;
        scanf("%c", &letter);
        index++;
    }

    // setting variable length to inputArray's length
    length = strlen(inputArr);

    // makes sure to add null terminator
    inputArr[length] = '\0';

    return;
}

int main()
{
    char str1[20];
    char str2[20];

    printf("Print str1: \n");

    // read input
    // basicamente scanf
    readString(str1);

    printf("\n");

    // checks if equal
    if (strcmp(str1, "No. Colder.") == 0)
    {
        printf("They are equal!\n");
    }




    return 0;
}

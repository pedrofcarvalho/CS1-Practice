/*
USE fflush(stdout) AFTER EVERY PRINTF ***********************************

Things to watch out for:
1. the loop iterates twice before asking for input (???????????????????) ask someone


//     {5, 9, 17, 23, 25, 45, 59, 63, 71, 89}
//      0  1   2   3   4   5   6   7   8   9

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readString(char normalName[]);

int main()
{
    // this part probably will change, uses too much memory....
    int *arr;
    int sizeOfArr;
    char inputArr[20];

    // asking for input
    printf("How big will the array be?\n");
    //fflush(stdout);
    scanf("%d", &sizeOfArr);

    arr = (int *) calloc(sizeOfArr, sizeof(int));

    // this for loop uses too much memory with bigger numbers
    for (int i = 0; i < sizeOfArr + 1; ++i)
    {
        arr[i] = i;
    }

    // start of logic for assignment

    // low, high and mid represent indexes
    int low = 0;
    int high = sizeOfArr - 1;
    int mid = (low + high) / 2;

    int guess; // variable that will hold the guess value once it's found
    int leftFlag = 0;
    int tryToFindLeft = 0;

    while (1/* when guess is found */) // complete here when know how to do it
    {
        // if tryToFindLeft is on, skip this part
        if (tryToFindLeft != 1)
        {
            printf("This is the program's guess: %d\n", arr[mid]);
            //fflush(stdout);
            printf("Make your decision:\n");
            //fflush(stdout);
            readString(inputArr);
        }

        else
        {
            printf("This is the program's guess: %d\n", arr[mid + 1]);
            printf("Make your decision:\n");
            readString(inputArr);

            if (strcmp(inputArr, "No. Colder.") == 0)
            {
                tryToFindLeft = 0;
                leftFlag = 1;
                //continue;
            }

            else
            {
                printf("Your guess is correct!\n");
                guess = arr[mid];
                break;
            }
        }


        if (strcmp(inputArr, "Yes.") == 0)
        {
            printf("Your guess is correct!\n");
            guess = arr[mid];
            break;
        }

        // is only used once
        else if (strcmp(inputArr, "No.") == 0)
        {
            printf("INCORRECT!\n\n");
            tryToFindLeft = 1;
            continue;
        }

        // means it's in the left side of the array
        else if (strcmp(inputArr, "No. Colder.") == 0)
        {
            //tryToFindLeft = 0;

            if (leftFlag == 1)
            {
                high = mid - 1;
                mid = (low + high) / 2;

                // what do I do with left?
                leftFlag = 0;
                continue;
            }

        }

    }






    return 0;
}


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

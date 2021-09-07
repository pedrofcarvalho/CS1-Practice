// only change range when guessing number next to it

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

void readString(char inputArr[]);

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
    // makes sure the loop doesn't iterate twice
    fflush(stdin);

    arr = (int *) calloc(sizeOfArr, sizeof(int));

    // this for loop uses too much memory with bigger numbers
    for (int i = 0; i < sizeOfArr; ++i)
    {
        arr[i] = i + 1;
    }

    // start of logic for assignment

    // low, high and mid represent indexes
    int low = 0;
    int high = sizeOfArr - 1;
    int mid = (low + high) / 2;

    int guess = 0; // variable that will hold the guess value once it's found
    int leftFlag = 0;
    int rightFlag = 0;

    while (guess == 0)
    {
        printf("This is the program's guess: %d\n", arr[mid]);
        printf("Make your decision:\n");
        // read input, SCANF
        readString(inputArr);

        if (rightFlag == 1 && (strcmp(inputArr, "No. Warmer.") == 0))
        {
            low = mid;
            mid = (low + high) / 2;
        }

        if (leftFlag == 1 && (strcmp(inputArr, "No. Colder.") == 0))
        {
            mid--;
            high = mid - 1;
            mid = (low + high) / 2;
            //leftFlag = 0;
            continue;
        }

        if (leftFlag == 1 && (strcmp(inputArr, "No. Warmer.") == 0))
        {
            ++mid;
            printf("This is the program's guess: %d\n", arr[mid]);
            printf("Make your decision:\n");
            readString(inputArr);

            if (strcmp(inputArr, "No. Colder.") == 0)
            {
                mid--;
                high = mid - 1;
                mid = (low + high) / 2;
            }

            // rest after "No. Warmer." logic.
            // *****************************************************

        }








        // "base case"
        if (strcmp(inputArr, "Yes.") == 0)
        {
            printf("Your guess is correct!\n");
            guess = arr[mid];
            break;
        }

        // will only run once
        else if (strcmp(inputArr, "No.") == 0)
        {
            ++mid;
            rightFlag = 1;
            leftFlag = 1;
        }






    }


    printf("Your guess is %d\n", guess);



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

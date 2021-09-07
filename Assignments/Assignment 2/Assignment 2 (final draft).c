#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void readString(char inputArr[]);
void clearString(char inputArr[]);

int main()
{
    // variables declaration
    int numRange;
    int guess = 0;
    int beforeMid;

    // Reads in how the range of values to guess (scanning)
    scanf("%d", &numRange);
    fflush(stdin);

    // variables that will hold range values
    int l = 0;
    int r = numRange - 1;
    int mid = (r + l) / 2;
    beforeMid = mid;

    // allocates numRange spaces into arr
    int *arr = (int *) calloc(numRange, sizeof(int));

    // fill in with numbers from 1 - numRange
    for (int i = 0; i < numRange; ++i)
    {
        arr[i] = i + 1;
    }

    // array that will store user's input
    char inputArr[20];


    // will loop until user inputs "Yes!!!" or "Game Over."
    // can only find a guess in those scenarios
    while (guess == 0)
    {
        // outputs the middle point of the range
        // guessing the midpoint
        printf("%d\n", arr[mid]);
        fflush(stdout);

        // see if answer is correct (scan user input)
        // USER EVALUATES FOR US, NUMBER AT MID
        clearString(inputArr);
        readString(inputArr);
        fflush(stdin);

        // for the midpoint
        // if yes, return the guess
        if (strcmp(inputArr, "Yes!!!") == 0)
        {
            // assigns guess to value at mid and exists loop
            guess = arr[mid];
            break;
        }

        else if (strcmp(inputArr, "No. No change.") == 0)
        {
            // assigns guess value at (beforeMid + mid) / 2
            // code logic will guarantee final answer will be there
            guess = arr[(beforeMid + mid) / 2];
            printf("%d\n", guess);
            fflush(stdout);

            // asks for input
            // input WILL be "Yes!!!" at this point
            clearString(inputArr);
            readString(inputArr);

            if (strcmp(inputArr, "Yes!!!") == 0)
            {
                // assigns guess to value at mid and exists loop
                guess = arr[mid];
                break;
            }
        }

        // checks if input is "Game Over." If it is, stop code
        else if (strcmp(inputArr, "Game Over.") == 0)
        {
            return 0;
        }

        // does nothing
        // place holder
        else
        {

        }

        // THIS IF STATEMENT EVALUATES NUMBER BEFORE MID
        // for the midpoint (CHECKPOINT AFTER CHECKING IF COLDER OR WARMER)
        // if not correct, no change, warmer or colder (evaluating input from number AT mid)
        if (strcmp(inputArr, "No.") == 0 || strcmp(inputArr, "No. Warmer.") == 0 || strcmp(inputArr, "No. Colder.") == 0 || strcmp(inputArr, "No. No change.") == 0)
        {
            // WILL CHECK NUMBER BEFORE MID
            // checks position mid - 1
            printf("%d\n", arr[mid - 1]);
            fflush(stdout);


            // USER EVALUATES FOR US, NUMBER BEFORE MID
            clearString(inputArr);
            readString(inputArr);
            fflush(stdin);

            // if yes, return the guess
            if (strcmp(inputArr, "Yes!!!") == 0)
            {
                // assigns guess to value at mid and exists loop
                guess = arr[mid];
                break;
            }


            // if wrong (evaluating number BEFORE mid)
            else
            {
                // if input is "No. Colder."
                if (strcmp(inputArr, "No. Colder.") == 0)
                {
                    // CHANGE THE RANGE

                    // beforeMid is used in case user enters "No. No change." in the future
                    beforeMid = mid;
                    l = mid + 1;
                    mid = (r + l) / 2;
                }


                // if input is "No. Warmer."
                else if (strcmp(inputArr, "No. Warmer.") == 0)
                {
                    // CHANGE THE RANGE

                    // beforeMid is used in case user enters "No. No change." in the future
                    beforeMid = mid;
                    r = mid - 2;
                    mid = (r + l) / 2;
                }

                // if input is "No. No change."
                else if (strcmp(inputArr, "No. No change.") == 0)
                {
                    // assigns guess value at (beforeMid + mid) / 2
                    // code logic will guarantee final answer will be there
                    guess = arr[(beforeMid + mid) / 2];
                    printf("%d\n", guess);
                    fflush(stdout);

                    // asks for input
                    // input WILL be "Yes!!!" at this point
                    clearString(inputArr);
                    readString(inputArr);

                    // input will be "Yes!!!"
                    if (strcmp(inputArr, "Yes!!!") == 0)
                    {
                        // assigns guess to value at mid and exists loop
                        guess = arr[mid];
                        break;
                    }
                }

                // checks if input is "Game Over." If it is, stop code
                else if (strcmp(inputArr, "Game Over.") == 0)
                {
                    return 0;
                }

                // if not correct ("No.")
                // this does nothing
                // just a place holder
                // necessary of previous else ifs
                else
                {
                    continue;
                }


            }

        }


    } // end of loop


    return 0;
}

// function that clears strings
void clearString(char inputArr[])
{
    int i, length = strlen(inputArr);

    for(i = 0; i < length; ++i)
    {
        inputArr[i] = '\0';
    }

    return;
}

// functions reads input with scanf
// given to us in Assignment 0
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


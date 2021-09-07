/*

ISSUES LIST:
1. SCANF ISSUE (ONLY SOLVABLE WITH FFLUSH) - line 28
2. ++i and --i issues - line 122

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BEGINNING 0
#define MIN 65
#define MAX 122

void createHandle(char normalName[], char handleName[]);
void readString(char normalName[]);
void clearString(char handleName[]);

int main()
{
    int numNames, i;

    // array to get name from input
    char normalName[100000];

    // array that stores the handle
    char handleName[100000];

    // prompting the user for the number of names
    scanf("%d", &numNames);
    fflush(stdin);

    // loops numNames times and stores the handle to the handleName array
    for (i = 0; i < numNames + 1; ++i)
    {
        // reads the input into normalName
        readString(normalName);

        // creates the handle
        createHandle(normalName, handleName);

        // displays handle as output
        printf("%s\n", handleName);

        // clear both strings
        clearString(handleName);
        clearString(normalName);
    }

    return 0;
}

// function that clears strings
void clearString(char handleName[])
{
    int i, length = strlen(handleName);

    for(i = 0; i < length; ++i)
    {
        handleName[i] = '\0';
    }

    return;
}

// function based on code shown in class
void readString(char normalName[])
{
    char letter;
    int index = 0, length;

    // reads first letter of input
    scanf("%c", &letter);

    // scanf for each character (better than using fgets)
    while (letter != '\n')
    {
        normalName[index] = letter;
        scanf("%c", &letter);
        index++;
    }

    // setting variable length to array's length
    length = strlen(normalName);

    // adding a new line to array for future use (on createHandle())
    // new line avoids out of bounds issues
    normalName[length] = '\n'; // NEW LINE SUCCESSFULLY ADDED (counts on string length)
    // makes sure to add null terminator
    normalName[++length] = '\0';

    return;
}

// fix logic issues
void createHandle(char normalName[], char handleName[])
{
    // index variables
    int i = 0, handleArrayIndex = 0, flag;
    // length variable reference
    int length = strlen(normalName); // line may not be needed

    // setting behavior if there's no space in the beginning of inputted String
    // sets the first index as the first letter of the string
    if (normalName[BEGINNING] != ' ') // BEGINNING = 0
    {
        handleName[0] = normalName[0];
        ++i;
        ++handleArrayIndex;
    }

    // setting behavior if there is 1 or more spaces in the beginning of inputted String
    else
    {
        while (normalName[i] == ' ')
        {
            i += 1;
        }

        handleName[BEGINNING] = normalName[i];
        ++handleArrayIndex;
    }

    // logic part that will create the rest of the handle
    // loops until it finds new line (until the end)
    while (normalName[i] != '\n')
    {
        // if statement check if there's a space, adds the letter before and after to the handleName string
        if (normalName[i] == ' ')
        {
            // FOR MULTIPLE SPACES AFTER THE FIRST NAME
            if (normalName[i + 1] == ' ')
            {
                handleName[handleArrayIndex] = normalName[i - 1];
                ++handleArrayIndex;
                while (normalName[i] == ' ')
                {
                    i += 1;
                }
                handleName[handleArrayIndex] = normalName[i];
                ++handleArrayIndex;
                continue;
            }

            // if the next character is either the end of string or another space
            // in this case, it just gets the previous letter and ends the function
            if ((normalName[i + 1] == '\n') || (normalName[i + 1] == ' '))
            {
                handleName[handleArrayIndex] = normalName[i - 1];
                ++handleArrayIndex;
                return;
            }

            // part that adds the letter before and after the space
            handleName[handleArrayIndex] = normalName[i - 1];
            // moves forward on the handleName array
            ++handleArrayIndex;
            handleName[handleArrayIndex] = normalName[i + 1];
            ++handleArrayIndex;
        }

        ++i;
    }

    // adds the last letter to the handleName array
    handleName[handleArrayIndex] = normalName[i - 1];

    return;
}


//void handleLetters(char normalName[], char handleName[], int i, int handleArrayIndex)
//{
//
//
//    return;
//}
//
//int checkIfArrayEmpty(char handleName[])
//{
//    int flag = 0, length = strlen(handleName);
//
//    for (int i = 0; i < length; ++i)
//    {
//        if (handleName[i] != '\0')
//        {
//            flag = 1;
//            return flag;
//        }
//    }
//
//    return flag;
//
//}

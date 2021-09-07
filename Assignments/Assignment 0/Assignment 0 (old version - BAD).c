#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100000 + 1
#define BEGINNING 0

void createHandle(char * normalName, char * handleName);
void readString(char * normalName);
char ** allocatesList(int numOfNames);
void destroyList(int numOfNames, char ** ListOfNames);

int main()
{
    // variable declaration
    int i, numNames;

    // reads in from input
    printf("Insert number of names:\n");
    scanf("%d", &numNames);
    fflush(stdin);

    // array of strings declaration
    char ** listOfNormalNames;
    char ** listOfHandleNames;

    // initialize array of strings
    listOfHandleNames = allocatesList(numNames);
    listOfNormalNames = allocatesList(numNames);

    // inserting names into normalNames arr
    for (i = 0; i < numNames; ++i)
    {
        printf("Insert name number %d here:\n", i + 1);
        readString(listOfNormalNames[i]);
    }

    // debug
    printf("\n");
    for (i = 0; i < numNames; ++i)
    {
        printf("Word %d is %s\n", i + 1, listOfNormalNames[i]);
    }

    // calls and creates the handle
    for (i = 0; i < numNames; ++i)
    {
        createHandle(listOfNormalNames[i], listOfHandleNames[i]);
    }

    // prints the handle
    for (i = 0; i < numNames; ++i)
    {
        printf("%s\n", listOfHandleNames[i]);
    }

    destroyList(numNames, listOfHandleNames);
    destroyList(numNames, listOfNormalNames);

    return 0;
}

// allocates memory for List of names
char ** allocatesList(int numOfNames)
{
    char ** ret = (char **) calloc(numOfNames, sizeof(char *));

    for (int i = 0; i < numOfNames; ++i)
    {
        ret[i] = (char *) calloc(NAME_LENGTH, sizeof(char));
    }

    return ret;
}


void destroyList(int numOfNames, char ** ListOfNames)
{
    int i;

    for (i = 0; i < numOfNames; ++i)
    {
        free(ListOfNames[i]);
    }

    free(ListOfNames);
}


// function based on code shown in class
void readString(char * normalName)
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
    normalName[index] = '\n'; // NEW LINE SUCCESSFULLY ADDED (counts on string length)

    // makes sure to add null terminator
    normalName[++index] = '\0';

    return;
}


void createHandle(char * normalName, char * handleName)
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

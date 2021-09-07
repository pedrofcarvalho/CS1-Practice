#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global constants
#define NAME_LENGTH 20 + 1
#define START 0
#define FALSE 0
#define TRUE 1

// function prototype
int nameChain(char ** ListOfNames, char ** finalStr, int * used, int len, int pos);
int isSorted(char ** finalStr, int size);

int main()
{
    // variable creation
    int numNames, i, j;
    char ** ListOfNames = NULL;
    char ** finalStr = NULL;
    int * used = NULL;

    // reads in number of names
    scanf("%d", &numNames);

    // creates an array of names
    ListOfNames = (char **) calloc(numNames, sizeof(char *));
    finalStr = (char **) calloc(numNames, sizeof(char *));
    used = (int *) calloc(numNames, sizeof(int));

    // allocates memory for each element in ListOfNames
    for (i = 0; i < numNames; ++i)
    {
        // creates the array that will hold the names "numNames" times
        ListOfNames[i] = (char *) calloc(NAME_LENGTH, sizeof(char));
        finalStr[i] = (char *) calloc(NAME_LENGTH, sizeof(char));

        // initializing values to 0
        used[i] = FALSE;

        // this loop initializes the finalStr with '\0'
        for(j = 0; j < NAME_LENGTH; ++j)
        {
            finalStr[i][j] = '\0';
        }
    }

    // scanning the words "numNames" times
    for (i = 0; i < numNames; ++i)
    {
        scanf("%s", ListOfNames[i]);
    }

    // function call
    // assigns the return value of the functions to ans (1 or 0)
    int ans = nameChain(ListOfNames, finalStr, used, numNames, START);

    // if names were properly organized, print it
    if (ans == 1)
    {
        // new line
        printf("\n");

        for (i = 0; i < numNames; ++i)
        {
            // print the string
            for (i = 0; i < numNames; i++)
            {
                printf("%s ", finalStr[i]);
            }
            // new line
            printf("\n");
        }
    }

    return 0;
}


// functions creates the pretty sentence
int nameChain(char ** ListOfNames, char ** finalStr, int * used, int numNames, int pos)
{
    int i, flag, lengthOfString;

    // base case
    if (numNames == pos)
    {
        // checks if the names are organized the way they should
        if (isSorted(finalStr, numNames) == 1)
        {
            // returns good
            return 1;
        }

        // not working
        // keep going
        return 0;
    }

    // the permutation part
    for (i = 0; i < numNames; i++)
    {
        if (used[i] == FALSE)
        {
            //set the value to used
            used[i] = TRUE;

            //Assign the name from the original array to the final one
            finalStr[pos] = ListOfNames[i];

            // recurse
            flag = nameChain(ListOfNames, finalStr, used, numNames, pos + 1);

            if (flag == 1)
            {
                // returns good
                return 1;
            }

            //undo the change = backtracking
            used[i] = FALSE;
            finalStr[pos] = NULL;
        }
    }

    // returns bad
    // keep going
    return 0;

}

// borrowed from office hours code: permutation.c
// functions checks if last letter of current word matches with next word's first letter
int isSorted(char ** arr, int size)
{
    int lengthOfString;

    for (int i = 0; i < size - 1; i++)
    {
        lengthOfString = strlen(arr[i]);

        if (arr[i][lengthOfString - 1] !=  arr[i + 1][0])
        {
            return 0; // last letter of current word doesn't match with next word's first letter
        }
    }

    return 1; // everything was ok
}

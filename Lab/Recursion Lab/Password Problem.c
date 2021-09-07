#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHRASE "adeflr"
#define FALSE 0
#define TRUE 1

int count;

//prototype for our recursive password thing
void perm(int *used, char * orignal, char * current, int len, int pos);

int main()
{
    int * used;  // letters that has been used
    char * original; // the original set of letters
    char *current;   // the current arrangement of letters
    int i;

    //Initialize the count to 0
    count = 0;

    //create memory
    used = (int *) calloc(strlen(PHRASE), sizeof(int));
    original = (char *) calloc(strlen(PHRASE), sizeof(char));
    current = (char *) calloc(strlen(PHRASE), sizeof(char ));

    // fill the arrays
    for (i = 0; i < strlen(PHRASE); i++)
    {
        used[i] = FALSE;
        original[i] = PHRASE[i];
        current[i] = '\0';
    }

    //run the recursive method
    perm(used, original, current, strlen(PHRASE), 0);

    //return a success
    return EXIT_SUCCESS; // EXIT_SUCCESS is a macro
}

//the recursive method that does the permutation
void perm(int * used, char * original, char * finalStr, int len, int pos)
{
    int i;

    //base case check if the finalStr position is at the end
    if (len == pos)
    {
        //don't do the recursion stuff
        return;
    }

    for (i = 0; i < len; i++)
    {
        if (used[i] == FALSE)
        {
            //set the value to used
            used[i] = TRUE;

            //Assign the value
            finalStr[pos] = original[i];

            //recurse
            perm(used, original, finalStr, len, pos + 1);

            //undo the change
            // backtracking
            used[i] = FALSE;
            finalStr[pos] = '\0';
        }
    }

    //not necessary
    //but if I need to return something it could be here!
    return;
}

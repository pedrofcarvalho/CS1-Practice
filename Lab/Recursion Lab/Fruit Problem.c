#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PHRASE "abcdefg"

int count;
const char *mapping[7];

//prototype for our recursive password thing
void perm(char * current, int index, int pos);

int main()
{
    char * cur; //the current arrangement of letters
    int i;
    //Initiallize the count to o
    count =0;
    //create memory
    cur = (char*) calloc(strlen(PHRASE), sizeof(char));
    //Fill the arrays
    for (i=0;i<strlen(PHRASE); i++)
    {
        cur[i]='\0';
    }
    //map the chars to their particular fruit
    //a->apple, b->grape and so on
    mapping[0]= "apple";
    mapping[1]= "grapes";
    mapping[2]="oranges";
    mapping[3]="grapefruit";
    mapping[4]="kiwi";
    mapping[5]="tomatoes";
    mapping[6]="banana";

    //Run the recursive method
    //start with fruit 0
    perm(cur,0,0);

    //return a success
    return EXIT_SUCCESS;
    }
//The recursive method theat does the permuation
void perm( char *current, int index, int pos)
{
    //Base case check if we have selected 3 fruit or not
    if (pos == 3)
    {
        //printf("%d\n", index);
        //print and update the count
        printf("%d\n", ++count);

        //print the string
        for (int i =0;i<3;i++)
        {
            int temp = current[i]-'a';

            //printf("%d", temp);
            printf("%s\t", mapping[temp]);
        }

        printf("\n");
        //Don't do the recursion stuff
        return;
    }

    //check if we have more fruit
    //make sure you understand why it is <= and <
    //because when index ==7 and pos ==3 we need to add
    //these in our answers as well
    //check if we have more fruit
    //make sure you understand why it is <= and <
    //because when index ==7 and pos ==3 we need to add
    //these in our answers as well

    if (index + 1 <= 7)
    {
        // do not take the current fruit/letters
        perm(current, index+1, pos);
        //Assign the value(choose the current fruit)
        current[pos] =PHRASE[index];
        //recursive
        perm(current, index+1, pos+1);
    }

    //not necessary
    //but if I need to return something it could be here
    return;
}

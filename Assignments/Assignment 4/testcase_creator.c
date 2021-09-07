/*
balduin
COP 3502C
FILE out, printing random testcases for the coin organization project
02 / 28 / 2021
*/

/*
I wanted to print a bunch of random numbers to a text file. This is to to practice
sorting and memory allacation.
This code was paired with coin_organization.c.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_CAP 100000
#define STR_LEN 5

char generateRandomChar(int);

//SPELLCASTING HAPPENS HERE
int main(void)
{
	FILE* ifp;
	ifp = fopen("individuals.txt", "w+");
  char id[STR_LEN + 1] = {0};

  srand(time(NULL));

	for (int i = 0; i < INT_CAP; i++)
	{
        for (int j = 0; j < STR_LEN; j++)
				{
            id[j] = generateRandomChar(j);
				}

		int tokens = rand() % INT_CAP;
    int bills = rand() % INT_CAP;
		fprintf (ifp, "%s %d %d\n", id, tokens, bills);
	}

  // X tokens are worth Y bills
  int tokenWorth = rand() % INT_CAP;
  int billWorth = rand() % INT_CAP;
  fprintf(ifp, "%d %d", rand() % INT_CAP, rand() % INT_CAP);
	fclose(ifp);
	return 0;
}

// Creates a random char character based on the current iteration of our string index.
char generateRandomChar(int iteration)
{
    char ret; 	// Initialization
    if ((iteration == 0) || (iteration == 1))
		{
        ret = rand() % (('Z' - 'A') + 1) + 'A'; // Range of characters for letters.
    }

		else
		{
        ret = rand() % (('9' - '0') + 1) + '0'; // Range of characters for numbers.
    }
		
    return ret;
}

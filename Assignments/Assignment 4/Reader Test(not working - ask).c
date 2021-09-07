#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE * fp, * fp2;
  int i, count1, count2, flag = 0;
  char fileName[30] = "as4_output.txt";
  char fileName2[30] = "myOutput.txt";
  char c;
  char namesList[150][150], namesList2[150][150];

  //printf("Write the name of the file 1 here:\n");
  //scanf("%s", fileName);

  //printf("Write the name of the file 2 here:\n");
  //scanf("%s", fileName2);

  // PART FOR FILE 1 ******************

  // opens the file, with fileName name
  fp = fopen(fileName, "r");

  // cheking for errors
  if (fp == NULL)
  {
    printf("Unable to open file\n");
    return 0;
  }

  // loops until last word
  while (fscanf(fp,"%s", namesList[i]) == 1)
  {
    ++i;
    continue;
  }

  // CLOSES FILE 1 *******************
  fclose(fp);

  // PART FOR FILE 2 ***********************
  fp2 = fopen(fileName2, "r");

  // cheking for errors
  if (fp2 == NULL)
  {
    printf("Unable to open file\n");
    return 0;
  }

  // reads in and stores values to namesList2
  while (fscanf(fp2,"%s", namesList2[i]) == 1)
  {
    //printf("%s\n", namesList2[i]);
    ++i;
    continue;
  }

  // for (i = 0; i < 101; i++)
  // {
  //   printf("%s\n", namesList2[i]);
  // }

  // CLOSES FILE 2
  fclose(fp2);

  count2 = sizeof(namesList) / sizeof(namesList[0]);

  printf("The size of namesList is: %d\n\n", count2);

  printf("These are the names in file 1:\n");
  for (i = 0; i < 101; i++)
  {
    printf("%s\n", namesList[i]);
  }


  // printf("\n\nThese are the names in file 2:\n");
  // for (i = 0; i < 101; i++)
  // {
  //   printf("%s\n", namesList2[i]);
  // }


  // for (i = 0; i < 100; i++)
  // {
  //   if (strcmp(namesList[i], namesList2[i]) != 0)
  //   {
  //     printf("They are NOT equal!\n");
  //     return 0;
  //   }
  // }
  //
  // printf("They are equal!\n");

  return 0;
}
















//

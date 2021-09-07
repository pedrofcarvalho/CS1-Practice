#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main()
{
  char ** myOutput = calloc(SIZE, sizeof(char*));
  char ** finalOutput = calloc(SIZE, sizeof(char*));

  // memory creation
  for (int i = 0; i < SIZE; ++i)
  {
    myOutput[i] = calloc(SIZE, sizeof(char));
    finalOutput[i] = calloc(SIZE, sizeof(char));
  }




  for (int i = 0; i < SIZE; ++i)
  {
    scanf("%s", myOutput[i]);
  }

  for (int i = 0; i < SIZE; ++i)
  {
    scanf("%s", finalOutput[i]);
  }


  // debug
  for (int i = 0; i < SIZE; ++i)
  {
    printf("%s\n", myOutput[i]);
  }
  printf("\n\nEnd of myOutput\n\n");

  for (int i = 0; i < SIZE; ++i)
  {
    printf("%s\n", finalOutput[i]);
  }
  // debug



  for (int i = 0; i < SIZE; ++i)
  {
    if (strcmp(myOutput[i], finalOutput[i]) != 0)
    {
      printf("Words don't match!!\n");
      return 0;
    }
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int teamMembersNum, moneyAmount, i;
  int * problemsSolved = calloc(teamMembersNum, sizeof(int));
  int moneyPerProblem = 0, problemSum = 0;

  scanf("%d", &teamMembersNum);
  scanf("%d", &moneyAmount);

  for(i = 0; i < teamMembersNum; ++i)
  {
    scanf("%d", &problemsSolved[i]);
  }

  // calculation part

  // sum number of problems
  for(i = 0; i < teamMembersNum; ++i)
  {
    problemSum += problemsSolved[i];
  }

  // calculates the ratio of money per problem
  moneyPerProblem = moneyAmount / problemSum;

  // prints the result for each team member
  for(i = 0; i < teamMembersNum; ++i)
  {
    printf("%d\n", moneyPerProblem * problemsSolved[i]);
  }


  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSorted(double * arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i+1])
            return 0; // out of order elements
    }
    return 1; // everything was in order! yay
}


int rec(double * input, double * perm, int n, int size, int * used)
{
    // perm[n] = ...; (n = 0, 1, 2, ..., size - 1)
    // base case
    if (n == size)
    {
        // 8 6 7 5 3 0 9
        // 8 6 7 5 3 9 0
        // we cannot modify any further value in the perm
        // our potential permutation

        if (isSorted(perm, size) == 1)
        {
            // the array is completely sorted
            for (int i = 0; i < size; i++)
                printf("%lf ", perm[i]);

            printf("\n");
            return 1; // sorted stop our search
        }

        return 0; // unsorted :( BOOOO!!!
    }

    // Look at every possible spot in the input
    for (int i = 0; i < size; i++)
    {
        // If the value in the input array is unused
        if (used[i] == 0)
        {
            // Store in the permutation
            perm[n] = input[i];

            used[i] = 1; // use the value

            if (rec(input, perm, n + 1, size, used))
                return 1;

            used[i] = 0; // unuse the value
        }
    }

    return 0;
}


int main()
{
    int size = 7;
    double arr[size];
    arr[0] = 8;
    arr[1] = 6;
    arr[2] = 7;
    arr[3] = 5;
    arr[4] = 3;
    arr[5] = 0;
    arr[6] = 9;

    double perm[size];
    int used[size];

    for (int i = 0; i < size; i++)
        used[i] = 0;
    // char ** words; // my recommendation
    // char words[n][max_word_size];

    int ans = rec(arr, perm, 0, size, used);
    printf("\nThis is \"ans\": %d\n", ans);

    return 0;
}

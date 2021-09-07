#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1. What is the big O of the following segment of C code wherea, b, and n are not constants?

    for (i = 0; i < a; i++)
    {
            for (j = 0; j < i; j++) // ---> USE SUMMATION FORMULA for i.
                                    // iterations: 0 + 1 + 2 + .... + a - 1
                                    // using formula -> (a(a + 1)) / 2 --> O(a^2)
            {
                sum += n;
            }

            for (k = 0; k < b; k++) // ---> runs (b * a) times
                                    // O(ab)
            {
                sum++;
            }
    }

    // add both values, since loops are NOT nested.

    /* Solution:

    O(a^2 + ab)

    */


    // 2. T(n) = 2T(n/2) + c

    /* solution:

    (solve with substitution)

    // finish with Dr. Meade's 2/5/2021 lecture notes
    T(n/2) =


    */


    return 0;
}

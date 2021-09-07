#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20 + 1

// Customer struct
typedef struct Customer
{
    char * name;                     // holds the name of customer
    long long int numOfTokens;       // holds the number of tokens that customer has
    long long int numOfBills;        // holds the number of bills that customer has
    long long int numUnits;          // will hold number of units after calculation
                                     // long long int to make sure it's big enough
} Customer;

// function protypes
Customer * createCustomer(int numOfCustomers);
void destroyCustomer(Customer * listOfCustomers, int numOfCustomers);
void merge(long long int * arr, int n);

int main()
{
    // variable declarations
    int i, j, numOfCustomers;
    long long int tokenVal, billVal;
    long long int calcUnits;
    Customer * listOfCustomers;

    // asking for input
    scanf("%d", &numOfCustomers);

    // variables for sorting
    long long int * finalArr = (long long int *) calloc(numOfCustomers, sizeof(long long int));
    int low = 0;
    int high = numOfCustomers - 1;

    // creates a list with size "numOfCustomers"
    listOfCustomers = createCustomer(numOfCustomers);

    // reads from input name, number of token and number of bills from each customer
    for (i = 0; i < numOfCustomers; ++i)
    {
        scanf("%s", listOfCustomers[i].name);
        scanf("%lld", &listOfCustomers[i].numOfTokens);
        scanf("%lld", &listOfCustomers[i].numOfBills);
    }

    // reading input for token to bill val
    scanf("%lld", &tokenVal);
    scanf("%lld", &billVal);

    // loop will calculate the number of units for every customer
    for (i = 0; i < numOfCustomers; ++i)
    {
        listOfCustomers[i].numUnits = (listOfCustomers[i].numOfTokens * billVal) + (listOfCustomers[i].numOfBills * tokenVal);
    }

    // adds values of units from each customer to finalArr (this arr will be sorted)
    // after sorting, will be compared to each customer to make sure
    for (i = 0; i < numOfCustomers; ++i)
    {
        finalArr[i] = listOfCustomers[i].numUnits;
    }

    // sorting call
    merge(finalArr, numOfCustomers);

    printf("\n"); // new line

    // backwards loop
    // this block of nested loops compares the values in finalArr (sorted array) with the number of units each customer has
    // prints when they are the same
    for (i = numOfCustomers - 1; i >= 0; --i)
    {
        for (j = 0; j < numOfCustomers; ++j)
        {
            if (finalArr[i] == listOfCustomers[j].numUnits)
            {
                printf("%s\n", listOfCustomers[j].name);
                break;
            }
        }
    }

    // freeing memory
    destroyCustomer(listOfCustomers, numOfCustomers);
    free(finalArr);

    return 0;
}

// allocates memory for Customer variables
Customer * createCustomer(int numOfCustomers)
{
    // initializes "listOfCustomers" by allocating memory into it
    // creates "numOfCustomers" elements
    Customer *listOfCustomers = (Customer *) calloc(numOfCustomers, sizeof(Customer));

    // allocates memory for every array
    for (int i = 0; i < numOfCustomers; ++i)
    {
        listOfCustomers[i].name = (char *) calloc(NAME_LENGTH, sizeof(char));
    }

    // every int value initialized to 0
    listOfCustomers->numOfBills = 0;
    listOfCustomers->numOfTokens = 0;
    listOfCustomers->numUnits = 0;

    // returns the array of customers
    return listOfCustomers;
}

// function frees memory
void destroyCustomer(Customer * listOfCustomers, int numOfCustomers)
{
    for (int i = 0; i < numOfCustomers; ++i)
    {
        free(listOfCustomers[i].name);
    }

    free(listOfCustomers);
}

// sorting algorithm (borrowed from Files -> Code -> Sort -> quick_merge.c)
// Sorts an array of size n
void merge(long long int * arr, int n)
{
    // base case first pl0x
    if (n <= 1)
    {
        return;// do nothing (already sorted B) )
    }
    // recursive step
    long long int mid = (n / 2);
    merge(arr, mid);
    merge(arr + mid, n - mid); // arr + mid == &(arr[mid])
                                // *(arr+mid) == arr[mid]
    long long int * ans = calloc(n, sizeof(long long int));
    long long int fptr = 0;
    long long int bptr = mid;
    for (int i = 0; i < n; i++)
    {
        if (fptr != mid && bptr != n && arr[fptr] <= arr[bptr])
        {
            ans[i] = arr[fptr];
            fptr++;
        }

        else if (fptr != mid && bptr != n && arr[fptr] > arr[bptr])
        {
            ans[i] = arr[bptr];
            bptr++;
        }

        else if (fptr == mid)
        {
            ans[i] = arr[bptr];
            bptr++;
        }

        else
        {
            ans[i] = arr[fptr];
            fptr++;
        }
    }

    memcpy(arr, ans, sizeof(long long int) * n);
    free(ans);

    return;
}

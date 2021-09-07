#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

// Customer struct
typedef struct Customer
{
    char * name; // holds the name of customer
    int numOfTokens; // holds the number of tokens that customer has
    int numOfBills; // holds the number of bills that customer has
    unsigned long long int numUnits; // will hold number of units after calculation
                                     // unsigned long long int to make sure it's big enough
} Customer;

unsigned long long int calculateUnits(int tokenVal, int billVal, int numOfTokens, int numOfBills);
Customer * createCustomer(int numOfCustomers);
void destroyCustomer(Customer * listOfCustomers, int numOfCustomers);

// sorting (put together later)
void merge(int * arr, int n);

int main()
{
    // variable declarations
    int i, numOfCustomers, calcUnits;
    int tokenVal, billVal;
    Customer * listOfCustomers;

    // asking for input
    scanf("%d", &numOfCustomers);

    // variables for sorting
    unsigned long long int *finalArr = (unsigned long long int *) calloc(numOfCustomers, sizeof(unsigned long long int));
    int low = 0;
    int high = numOfCustomers - 1;

    // creates a list with size "numOfCustomers"
    listOfCustomers = createCustomer(numOfCustomers);

    // reads from input name, number of token and number of bills from each customer
    for (int i = 0; i < numOfCustomers; ++i)
    {
        scanf("%s", listOfCustomers[i].name);
        scanf("%d", &listOfCustomers[i].numOfTokens);
        scanf("%d", &listOfCustomers[i].numOfBills);
    }

    // reading input for token to bill val
    scanf("%d", &tokenVal);
    scanf("%d", &billVal);

    // loop will calculate the number of units for every customer
    for (int i = 0; i < numOfCustomers; ++i)
    {
        calcUnits = calculateUnits(tokenVal, billVal, listOfCustomers[i].numOfTokens, listOfCustomers[i].numOfBills);
        listOfCustomers[i].numUnits = calcUnits;
    }


    // adds values of units from each customer to finalArr (this arr will be sorted)
    // after sorting, will be compared to each customer to make sure
    for (int i = 0; i < numOfCustomers; ++i)
    {
        finalArr[i] = listOfCustomers[i].numUnits;
    }

    // sorting call (GOOD)
    merge(finalArr, numOfCustomers);

    printf("\n"); // new line

    // backwards loop
    // this block of nested loops compares the values in finalArr (sorted array) with the number of units each customer has
    // prints when they are the same
    for (int i = numOfCustomers - 1; i >= 0; --i)
    {
        for (int j = 0; j < numOfCustomers; ++j)
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

// function calculates units
unsigned long long int calculateUnits(int tokenVal, int billVal, int numOfTokens, int numOfBills)
{
    // variables that will be used to calculate number of units
    unsigned long long int units;
    unsigned long long int tokenUnits;
    unsigned long long int billUnits;

    // calculation process
    tokenUnits = billVal * numOfTokens;
    billUnits = tokenVal * numOfBills;
    units = billUnits + tokenUnits;

    // return number of units
    return units;
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
void merge(int * arr, int n)
{
    // base case first pl0x
    if (n <= 1) {
        return;// do nothing (already sorted B) )
    }
    // recursive step
    int mid = (n / 2);
    merge(arr, mid);
    merge(arr + mid, n - mid); // arr + mid == &(arr[mid])
                               // *(arr+mid) == arr[mid]
    int * ans = calloc(n, sizeof(int));
    int fptr = 0;
    int bptr = mid;
    for (int i = 0; i < n; i++) {
        if (fptr != mid && bptr != n && arr[fptr] <= arr[bptr]) {
            ans[i] = arr[fptr];
            fptr++;
        } else if (fptr != mid && bptr != n && arr[fptr] > arr[bptr]) {
            ans[i] = arr[bptr];
            bptr++;
        } else if (fptr == mid) {
            ans[i] = arr[bptr];
            bptr++;
        } else {
            ans[i] = arr[fptr];
            fptr++;
        }
    }

    memcpy(arr, ans, sizeof(int) * n);
    free(ans);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct author_t
{
    char name[20];
    int birthYear;
    int publishings;
} author_t;

typedef struct book_t
{
    char name[20];
    int year;
    int numAuthors;
    author_t * authors;
} book_t;

int main()
{
    int i, j, numBooks;
    book_t * bookArr;

    // BEGINNING OF PART 1
    // 1. Write a segment of code that creates the memory for the list of books(in the form of an array) and authorsbased on the input format specified above.


    // reads from input
    scanf("%d", &numBooks);

    // allocates memory for bookArr (creates array)
    bookArr = (book_t *) calloc(numBooks, sizeof(book_t));

    for (i = 0; i < numBooks; ++i)
    {
        // block of code sets values to each part of struct book
        scanf("%s", bookArr[i].name);
        scanf("%d", &bookArr[i].year);
        scanf("%d", &bookArr[i].numAuthors);

        // bookArr is not a pointer at this point ******
        // allocate memory for struct author
        bookArr[i].authors = (author_t *) calloc(bookArr[i].numAuthors, sizeof(author_t));

        // initializes the values inside struct author
        for (j = 0; j < bookArr[i].numAuthors; ++j)
        {
            scanf("%s", bookArr[i].authors[j].name);
            scanf("%d", &bookArr[i].authors[j].birthYear);
            scanf("%d", &bookArr[i].authors[j].publishings);
        }
    }

    // END OF PART 1



    // BEGINNING OF PART 2
    // 2. Write a segment of code that frees the memory that you created.

    // frees memory from INSIDE -> OUT

    for (i = 0; i< numBooks; ++i)
    {
//        for (j = 0; j < bookArr[i].numAuthors; ++j)
//        {
//            free(bookArr[i].authors[j].birthYear);
//            free(bookArr[i].authors[j].name);
//            free(bookArr[i].authors[j].publishings);
//        }

        free(bookArr[i].author);

        // to avoid memory issues (only optional to avoid issues)
        bookArr[i].authors = NULL;
    }

    free(bookArr);
    bookArr = NULL;



    // END OF PART 2



    // BEGINNING OF PART 3
    // 3. What issues could you runinto with updating author information?

    // If an author for a book is updated, their update won't be propogated to the other books that author is listed


    return 0;
}

// Board is an array of ranks and Rank is an array of Pieces

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 10

// Some typedefs to make life easier
typedef struct Piece Piece;
typedef struct List List;
typedef struct Board Board;

// Piece structs
struct Piece
{
    int row, column, ind;
};

// ranks / rows or columns
struct List
{
    int ID;
    // array of Piece structs
    Piece ** arr; // this one
    int size, cap;
};

struct Board
{
    // array of Rank stucts
    List ** arr;
    int size, cap;
};

// Prototypes
Board * createBoard();
List * createRank(int ID);
Piece * createPiece(int row, int column, int index);
void destroyBoard(Board * board);
void destroyRank(List * list);
void destroyPiece(Piece * piece);
void addPieceToRank(List * row, Piece * currentPiece);
void addRankToBoard(Board * currentBoard, List * row);
void expandRank(List * row);
void expandBoard(Board * currentBoard);
List * findRank(Board * currentBoard, int ID);

int main()
{
    // variable declaration
    int numPieces, i, j, row, col;

    // reads how many pieces there will have
    scanf("%d", &numPieces);

    // board of rows exists
    Board * rows = createBoard();
    Board * cols = createBoard();

    // create the array of pieces
    Piece **PieceList = (Piece **) calloc(numPieces, sizeof(Piece *));
    List * currRow = NULL;
    List * currCol = NULL;

    // THIS LOOP READS THE PIECES AND SETS THE BOARD
    for (i = 0; i < numPieces; ++i)
    {
        // reads input
        scanf("%d %d", &row, &col);

        // read in current piece
        PieceList[i] = createPiece(row, col, i);

        // find the row and column for the pieces
        currRow = findRank(rows, row);
        currCol = findRank(cols, col);

        // add the Pieces created to rank
        addPieceToRank(currRow, PieceList[i]);
        addPieceToRank(currCol, PieceList[i]);
    }


    // this loop is checking for threats and printing
    for (i = 0; i < numPieces; i++)
    {
        row = PieceList[i]->row;
        col = PieceList[i]->column;

        // storing row and column to currRow and currColumn
        currRow = findRank(rows, row);
        currCol = findRank(cols, col);

        // creating pointers
        Piece * rowBefore = NULL, *rowAfter = NULL, * colBefore = NULL, * colAfter = NULL;

        // checking every column of rows
        for (j = 0; j < currRow->size; j++)
        {
            // checks for threats
            if (currRow->arr[j]->column < col && (!colBefore || colBefore->column < currRow->arr[j]->column))
            {
                // set the colBefore to the the current "index" (if finds a threat)
                colBefore = currRow->arr[j];
            }

            // checks for threats
            if (currRow->arr[j]->column > col && (!colAfter || colAfter->column > currRow->arr[j]->column))
            {
                // set the colAfter to the the current "index" (if finds a threat)
                colAfter = currRow->arr[j];
            }
        }

        // checking every row of columns
        for (j = 0; j < currCol->size; ++j)
        {
            if (currCol->arr[j]->row < row && (!rowBefore || rowBefore->row < currCol->arr[j]->row))
            {
                // set the rowBefore to the the current "index" (if finds a threat)
                rowBefore = currCol->arr[j];
            }

            if (currCol->arr[j]->row > row && (!rowAfter || rowAfter->row > currCol->arr[j]->row))
            {
                // set the rowAfter to the the current "index" (if finds a threat)
                rowAfter = currCol->arr[j];
            }
        }


        // sets threats to zero
        int threats = 0;


        // series of if statements checking if rowBefore/After, colBefore/After are NULL
        // if they are not NULL, adds 1 to threats

        if (rowBefore != NULL)
        {
            threats++;
        }

        if (rowAfter != NULL)
        {
            threats++;
        }

        // just changed it
        if (colBefore != NULL)
        {
            threats++;
        }

        // just changed it
        if (colAfter != NULL)
        {
            threats++;
        }

        // checking if no threat was found
        if (colAfter == NULL && colBefore == NULL && rowAfter == NULL && rowBefore == NULL)
        {
            // prints 0 and iterate the loop again
            printf("0\n");
            continue;
        }

        // prints threats
        printf("%d ", threats);


        // 1
        // Prints if not NULL
        if (rowBefore != NULL)
        {
            printf("%d ", rowBefore->ind + 1);
        }

        // 2
        // Prints if not NULL
        if (rowAfter != NULL)
        {
            printf("%d ", rowAfter->ind + 1);
        }

        // 3
        // Prints if not NULL
        if (colBefore != NULL)
        {
            printf("%d ", colBefore->ind + 1);
        }

        // 4
        // Prints if not NULL
        if (colAfter != NULL)
        {
            printf("%d ", colAfter->ind + 1);
        }

        // new line
        printf("\n");
    }

    return 0;
}

// ??
Board * createBoard()
{
    // allocates memory for Board *
    Board *ret = (Board *) calloc (1, sizeof(Board));

    ret->size = 0;
    ret->cap = DEFAULT_CAP;

    // allocates memory for arr (WHAT DOES IT DO THO?) (CONTEXT)
    ret->arr = (List **) calloc(DEFAULT_CAP, sizeof(List *));

    return ret;

}

List * createRank(int ID)
{
    // allocates memory for List *
    List *ret = (List *) calloc(1, sizeof(List));

    // sets values
    ret->ID = ID;
    ret->size = 0;
    ret->cap = DEFAULT_CAP;

    // allocates memory for arr (WHAT DOES IT DO THO?) (CONTEXT)
    ret->arr = (Piece **) calloc(DEFAULT_CAP, sizeof(Piece*));

    return ret;
}

Piece * createPiece(int row, int column, int index)
{
    // allocates memory to Piece *
    Piece *ret = (Piece *) calloc(1, sizeof(Piece));

    // sets the values
    ret->column = column;
    ret->row = row;
    ret->ind = index;

    return ret;
}

void expandRank(List * row)
{
    // stores cap * 2
    int newCap = row->cap * 2;

    // reallocates for arr
    row->arr = realloc(row->arr, newCap * sizeof(Piece *));

    // set cap = newCap
    row->cap = newCap;
}

void expandBoard(Board * currentBoard)
{
    // sets newCap double the capacity
    int newCap = currentBoard->cap * 2;

    // reallocates for arr
    currentBoard->arr = realloc(currentBoard->arr, newCap * sizeof(List *));

    // set cap = newCap
    currentBoard->cap = newCap;
}

// free board
void destroyBoard(Board * board)
{
    free(board);
}

// free list
void destroyRank(List * list)
{
    free(list);
}

// free piece
void destroyPiece(Piece * piece)
{
    free(piece);
}

// adds a Piece to a Rank
void addPieceToRank(List * row, Piece * currentPiece)
{
    // checks if the Rank is full
    if (row->size == row->cap)
    {
        expandRank(row);
    }

    // adding the Piece to the end the list (because of row->size that indicates the last element)
    row->arr[row->size] = currentPiece;
    row->size++;
}

// adds a Rank to a Board
void addRankToBoard(Board * currentBoard, List * row)
{
    // checks if the Board is full
    if (currentBoard->size == currentBoard->cap)
    {
        expandBoard(currentBoard);
    }

    // adding the Rank to the end the list (because of row->size that indicates the last element)
    currentBoard->arr[currentBoard->size] = row;
    currentBoard->size++;
}

// not sure what to return;
List * findRank(Board * currentBoard, int ID)
{
    List *curRank;
    int i;

    for (i = 0; i < currentBoard->size; ++i)
    {
        // sets curRank to the rank in the for loop
        curRank = currentBoard->arr[i];

        // checks if ID is the same
        if (ID == curRank->ID)
        {
            return curRank;
        }
    }

    // allocates memory for
    curRank = createRank(ID);

    // adds the new Rank to the Board
    addRankToBoard(currentBoard, curRank);

    // returns the curRan
    return curRank;
}

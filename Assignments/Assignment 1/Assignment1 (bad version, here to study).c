// Board is an array of ranks and Rank is an array of Pieces

// so for clarification, so I can finally attempt to start, we create 2 Boards, then we create one row and one column, each being the "Board"
// And after that, we put the pieces into the rows and columns, correct?

//addPieceToRank and addRankToBoard

// FOR LOOP 1 AND 2 NO CLUE WHAT TO DO *******************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 10

// Some typedefs to make life easier
typedef struct Piece Piece;
typedef struct List List;
typedef struct Board Board;

// Our structs
struct Piece {
    int row, column, ind;
};

// ranks / rows or columns
struct List {
    int ID;
    // array of Piece structs
    Piece ** arr; // this one
    int size, cap;
};

struct Board {
    // array of
    List ** arr; // this one
    int size, cap;
};

// Prototypes
Board * createBoard(); //create user list, used for row/column                  // done
List * createRank(int ID); // create user  -----------------------------------> // done
Piece * createPiece(int row, int column, int index); // ----------------------> // done
void destroyBoard(Board * board); // -----------------------------------------> // done
void destroyRank(List * list); //used for row/columns ------------------------> // done
void destroyPiece(Piece * piece);//          ---------------------------------> // done
void addPieceToRank(List * row, Piece * currentPiece); // used for row/column   // MIGHT BE DONE // addFriendtoUser
void addRankToBoard(Board * currentBoard, List * row); // used for row/column   // MIGHT BE DONE // addUsertoUserList
void expandRank(List * row); // used for row/column --------------------------> // done
void expandBoard(Board * currentBoard); // used for row/column                  // done
List * findRank(Board * currentBoard, int ID); // used for row/column           // MIGHT BE DONE

int main()
{

    int numPieces, i, j, row, col;
    printf("How many pieces do you want?\n");
    scanf("%d", &numPieces);

    // board of rows exists
    Board * rows = createBoard();
    Board * cols = createBoard();

    // create the array of pieces
    Piece **PieceList = (Piece **) calloc(numPieces, sizeof(Piece *));
    List * currRow = NULL;
    List * currCol = NULL;

    // loop over the pieces
    // FOR LOOP 1
    // THIS LOOP READS THE PIECES AND SETS THE BOARD
    for (i = 0; i < numPieces; ++i)
    {
        // not sure if this is suppose to be here? **************
        printf("What is the position of your piece (row -> column)\n");
        scanf("%d %d", &row, &col);

        // this one is right
        // read in current piece
        PieceList[i] = createPiece(row, col, i);

        // find the row and column for the pieces
        // CHECK FIND RANK FUNCTION
        currRow = findRank(rows, row);
        currCol = findRank(cols, col);

        // DOUBLE CHECK THIS PART *********************
        addPieceToRank(currRow, PieceList[i]);
        addPieceToRank(currCol, PieceList[i]);
    }

    // separates the input from output
    printf("\n");

    // checking for threats (?)
    // FOR LOOP 2
    for (i = 0; i < numPieces; ++i)
    {
        row = PieceList[i]->row;
        col = PieceList[i]->column;

        // storing row and column to currRow and currColumn
        currRow = findRank(rows, row);
        currCol = findRank(cols, col);

        // creating pointers
        Piece * rowBefore = NULL, *rowAfter = NULL, * colBefore = NULL, * colAfter = NULL;

        // are these right?? // I THINK THIS IS RIGHT
        // checking every column of rows
        for (j = 0; j < currRow->size; ++j)
        {
            if (currRow->arr[j]->column < col && (!colBefore || colBefore->column < currRow->arr[j]->column))
            {
                colBefore = currRow->arr[j];
            }

            if (currRow->arr[j]->column > col && (!colAfter || colAfter->column > currRow->arr[j]->column))
            {
                colAfter = currRow->arr[j];
            }
        }

        // are these right??
        // checking every row of columns

        // I THINK THIS IS RIGHT !!!!!!!!!!!!!!!
        for (j = 0; j < currCol->size; ++j)
        {
            if (currCol->arr[j]->row < row && (!rowBefore || rowBefore->row < currCol->arr[j]->row))
            {
                rowBefore = currCol->arr[j];
            }

            if (currCol->arr[j]->row > row && (!rowAfter || rowAfter->row > currCol->arr[j]->row))
            {
                rowAfter = currCol->arr[j];
            }
        }

        // 3
        // 1 1
        // 5 5
        // 6 1

/*         4
           1 1
           2 1
           4 1
           2 2

*/
        // this part got me confused
        // from here until the end of main, I don't understand ****************************************************
        int threats = 0;
        if (rowBefore != NULL)
        {
            ++threats;
        }

        if (rowAfter != NULL)
        {
            ++threats;
        }

        // just changed it
        if (colBefore != NULL)
        {
            ++threats;
        }

        // just changed it
        if (colAfter != NULL)
        {
            ++threats;
        }

        // checking if no threat was found
        if (colAfter == NULL && colBefore == NULL && rowAfter == NULL && rowBefore == NULL)
        {
            printf("0\n");
            continue;
        }

        printf("%d ", threats);

        // why is it now working??
        // idk what this does
        if (colBefore != NULL)
        {
            printf("%d ", colBefore->ind + 1);
        }

        if (rowBefore != NULL)
        {
            printf("%d ", rowBefore->ind + 1);
        }

        if (rowAfter != NULL)
        {
            printf("%d ", rowAfter->ind + 1);
        }

        if (colAfter != NULL)
        {
            printf("%d ", colAfter->ind + 1);
        }

        printf("\n");
    }


    // DESTROY MEMORY HERE
    // DONT WORRY I WILL DO IT AS SOON AS I GET IT RUNNING

    return 0;
}

// ??
Board * createBoard()
{
    Board *ret = (Board *) calloc (1, sizeof(Board));

    ret->size = 0;
    ret->cap = DEFAULT_CAP;

    // allocates memory for arr (WHAT DOES IT DO THO?) (CONTEXT)
    ret->arr = (List **) calloc(DEFAULT_CAP, sizeof(List *));

    return ret;

}

List * createRank(int ID)
{
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
    Piece *ret = (Piece *) calloc(1, sizeof(Piece));

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

    int newCap = currentBoard->cap * 2;

    // reallocates for arr
    currentBoard->arr = realloc(currentBoard->arr, newCap * sizeof(List *));

    // set cap = newCap
    currentBoard->cap = newCap;
}


void destroyBoard(Board * board)
{
    free(board);
}

void destroyRank(List * list)
{
    free(list);
}

void destroyPiece(Piece * piece)
{
    free(piece);
}

// checking (not done yet)
void addPieceToRank(List * row, Piece * currentPiece)
{
    // checks if its full
    if (row->size == row->cap)
    {
        expandRank(row);
    }

    // adding the Piece to the end the list (because of row->size that indicates the last element)
    row->arr[row->size] = currentPiece;
    row->size++;
}

// checking (not done yet)
void addRankToBoard(Board * currentBoard, List * row)
{
    if (currentBoard->size == currentBoard->cap)
    {
        expandBoard(currentBoard);
    }

    currentBoard->arr[currentBoard->size] = row;
    currentBoard->size++;
}

// not sure what to return;
// probably wrong (ASK HERE *************************************************************************)
List * findRank(Board * currentBoard, int ID)
{
    List *curRank; // this line probably wrong
    int i;

    for (i = 0; i < currentBoard->size; ++i)
    {
        curRank = currentBoard->arr[i];

        if (ID == curRank->ID)
        {
            return curRank;
        }
    }

    curRank = createRank(ID);

     // THIS MIGHT BE WRONG        // here   <-- change
    addRankToBoard(currentBoard, curRank); // this line probably wrong


    return curRank; // this line probably wrong
}



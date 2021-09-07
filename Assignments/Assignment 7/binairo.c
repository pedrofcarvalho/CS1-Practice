
#include <stdio.h>
#include <stdlib.h>

#define in32(x) scanf("%d", &x)
#define WHITE 1
#define BLACK 2
#define EMPTY 0
#define IMPOSSIBLE 0
#define POSSIBLE 1

int ** grid, r, c;

void read();
int solve(int rr, int cc);
void print();
int isValid(int rr, int cc);

int main()
{
    read();
    solve(0,0);
    print();
    return 0;
}

void read()
{
    scanf("%d", &r);
    scanf("%d", &c);
    grid = calloc(r, sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        grid[i] = calloc(c, sizeof(int));
        char row[c + 1];
        scanf("%s", row);
        for (int j = 0; j < c; j++)
        {
            if (row[j] == '_')
                grid[i][j] = EMPTY;
            else if (row[j] == 'W')
                grid[i][j] = WHITE;
            else
                grid[i][j] = BLACK;
        }
    }
}

int solve(int rr, int cc)
{
    if (rr == r) // at bottom of grid
        return POSSIBLE;

    if (cc == c) // at end of the row
        return solve(rr + 1, 0);

    if (grid[rr][cc] != EMPTY)
    {
        // is this filled in
        if (isValid(rr, cc))
            return solve(rr, cc + 1);
        return IMPOSSIBLE;
    }

    // we are in the grid and the spot is empty

    // try white
    grid[rr][cc] = WHITE;
    if (isValid(rr, cc) == POSSIBLE)
        if (POSSIBLE == solve(rr, cc + 1))
            return POSSIBLE;

    // try black
    grid[rr][cc] = BLACK;
    if (isValid(rr, cc) == POSSIBLE)
        if (POSSIBLE == solve(rr, cc + 1))
            return POSSIBLE;

    // return fail
    grid[rr][cc] = EMPTY;
    return IMPOSSIBLE;
}

void print() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c", grid[i][j] == WHITE ? 'W' : 'B');
        }
        printf("\n");
    }
}

// The hard part :(
// 1. each row and column must have
//    an equal number of white and
//    black circles
// 2. More than two circles of the
//    same color can't adjacent
//    BBB WWW bad :(
//
//    BB good
//    BW
//
// 3. rows and columns are unique
int  isValid(int rr, int cc)
{
    // rule 1
    int wR=0, bR=0, wC=0, bC=0;

    // column loop
    for (int i = 0; i < r; i++)
    {
        if (grid[i][cc] == WHITE)
            wC++;

        else if (grid[i][cc] == BLACK)
            bC++;
    }

    if (wC * 2 > r || bC * 2 > r)
        return IMPOSSIBLE;

    // row loop
    for (int i = 0; i < c; i++)
    {
        if (grid[rr][i] == WHITE)
            wR++;

        else if (grid[rr][i] == BLACK)
            bR++;
    }

    if (wR * 2 > c || bR * 2 > c)
        return IMPOSSIBLE;

    // rule 2
    //      left side
    //          r
    if (cc < c - 2 &&
            grid[rr][cc] == grid[rr][cc + 1] &&
            grid[rr][cc] == grid[rr][cc + 2])
        return IMPOSSIBLE; // 3 in a row
    //          c
    if (rr < r - 2 &&
            grid[rr][cc] == grid[rr + 1][cc] &&
            grid[rr][cc] == grid[rr + 2][cc])
        return IMPOSSIBLE;

    //      right side
    //          r
    if (cc >= 2 &&
            grid[rr][cc] == grid[rr][cc - 1] &&
            grid[rr][cc] == grid[rr][cc - 2])
        return IMPOSSIBLE;
    //          c
    if (rr >= 2 &&
            grid[rr][cc] == grid[rr - 1][cc] &&
            grid[rr][cc] == grid[rr - 2][cc])
        return IMPOSSIBLE;

    //      middle
    //          r
    if (cc >= 1 && cc < c - 1 &&
            grid[rr][cc] == grid[rr][cc - 1] &&
            grid[rr][cc] == grid[rr][cc + 1])
        return IMPOSSIBLE;
    //          c
    if (rr >= 1 && rr < r - 1 &&
            grid[rr][cc] == grid[rr + 1][cc] &&
            grid[rr][cc] == grid[rr - 1][cc])
        return IMPOSSIBLE;

    // rule 3
    for (int i = 0; i < r; i++) {
        if (i == rr) continue;
        int isSame = 1;
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != grid[rr][j] ||
                    grid[i][j] == EMPTY)
                isSame = 0;
        }
        if (isSame) return IMPOSSIBLE;
    }
    for (int i = 0; i < c; i++) {
        if (i == cc) continue;
        int isSame = 1;
        for (int j = 0; j < r; j++) {
            if (grid[j][i] != grid[j][cc] ||
                    grid[j][i] == EMPTY)
                isSame = 0;
        }
        if (isSame) return IMPOSSIBLE;
    }

    // No rule has been violate
    return POSSIBLE;
}

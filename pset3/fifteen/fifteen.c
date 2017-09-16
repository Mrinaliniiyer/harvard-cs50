/***********************
*       Solved         *
*         by           *
*     alanthony333     *
***********************/

/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // TODO
    // create variable area for faster implementation in for loop
    int area = d * d;

    // iterate through the 3 arrays, or through the rows
    for(int i = 0; i < d; i++) {

        // iterate through the contents of each array, or through the columns
        for(int j = 0; j < d; j++) {

            // since this is board initialization, count in decreasing order
            board[i][j] = --area;
        }
    }

    // if tiles are even, tiles which contains 1 and 2 have to be swapped
    // variable area shouldn't be used since its value is used in for loop
    if(d * d % 2 == 0) {
        printf("%i\n", area);
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    // iterate through the 3 arrays, or through the rows
    for(int i = 0; i < d; i++) {

        // iterate through the contents of each array, or through the columns
        for(int j = 0; j < d; j++) {

            // if iteration comes to the tile with 0
            if(board[i][j] == 0) {

                // print a space and underscore, the BLANK TILE
                printf(" _");

            } else {

                // in %3i, 3 is used instead of 2 to accomodate readability of 2 digit integers
                printf("%3i", board[i][j]);
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // TODO
    int area = d * d;


    if(tile > area - 1 || tile < 1) {
        return false;
    }

    int i_tile = 0;
    int j_tile = 0;

    // iterate through the arrays via linear search to find the tile selected
    // iterate through the 3 arrays, or through the rows
    for(int i = 0; i < d; i++) {

        // iterate through the contents of each array, or through the columns
        for(int j = 0; j < d; j++) {

            // when we find the tile in the arrays
            if(board[i][j] == tile) {

                // convert the i and j of the tile to a variable specific to the tile
                i_tile = i;
                j_tile = j;
            }

        }
    }

    // check first if tile is not in the edge, then check if BLANK TILE is on its left
    if(j_tile > 0 && board[i_tile][j_tile - 1] == 0) {

        // if it is, swap the coordinates of the two
        board[i_tile][j_tile - 1] = board[i_tile][j_tile];
        board[i_tile][j_tile] = 0;
        return true;

    // check first if tile is not in the edge, then check if BLANK TILE is on its right
    } else if(j_tile < d - 1 && board[i_tile][j_tile + 1] == 0) {

        // if it is, swap the coordinates of the two
        board[i_tile][j_tile + 1] = board[i_tile][j_tile];
        board[i_tile][j_tile] = 0;
        return true;

    // check first if tile is not in the edge, then check if BLANK TILE is above it
    } else if(i_tile > 0 && board[i_tile - 1][j_tile] == 0) {

        // if it is, swap the coordinates of the two
        board[i_tile - 1][j_tile] = board[i_tile][j_tile];
        board[i_tile][j_tile] = 0;
        return true;

    // check first if tile is not in the edge, then check if BLANK TILE is below it
    } else if(i_tile < d - 1 && board[i_tile + 1][j_tile] == 0) {

        // if it is, swap the coordinates of the two
        board[i_tile + 1][j_tile] = board[i_tile][j_tile];
        board[i_tile][j_tile] = 0;
        return true;
    }

    return false;

}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // TODO
    // set counter to check tile number
    int counter = 0;

    // iterate through the 3 arrays, or through the rows
    for(int i = 0; i < d; i++) {

        // iterate through the contents of each array, or through the columns
        for(int j = 0; j < d; j++) {

            // add 1 to the counter for each iteration
            counter++;

            // since zero-based, check if counter indeed is less than the area
            // then check if counter and board coordinates are not similar
            // note: checking the dissimilarity is easier than the opposite which produces error
            if(counter < d * d && counter != board[i][j]) {

                return false;
            }
        }
    }

    return true;
}

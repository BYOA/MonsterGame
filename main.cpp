//Author: BYOA
//Version 1.0

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/*WHAT TO DO IN PROGRAM:

1. ensure that char cannot result in multiple inputs. That breaks the game.
2. Add user defined type for movement in rows and columns. Use structures.
3. Add enemy movement with random generation. (CHECK)
4. Ensure enemy movement does not go out-of-bounds. (CHECK)
4. Clean up code into a more useable state. Do this with different versions.
5. Anctipate input error.

*/



using namespace std;

void DisplayBoard (char grid[9][9]);

int main ()
{
    /* initialize random seed: */
  srand (time(NULL));


    char board[9][9];
    //intitalising board
        for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            board[x][y] = '.';

        }
    }

    int treasurecol = 8;
    int treasurerow = 8;
    board[treasurerow][treasurecol] = 'X'; //treasure
    //3 enemies

    int e1row = 4;
    int e1col = 6;

    int e2row = 6;
    int e2col = 2;

    int e3row = 3;
    int e3col = 4;

    board[e1row][e1col] = 'T';
    board[e2row][e2col] = 'T';
    board[e3row][e3col] = 'T';

    int playercol = 1;
    int playerrow =1;
    board[playerrow][playercol] = 'G'; //player


    //displaying board


    bool gameover = false;
    int turncount = 1;

    while (!(gameover))
    {
    system("CLS");

        DisplayBoard (board);

        char choice;
        cout << "Turn " << turncount << endl;
        cout << "Which way will you move? (l,r,u,d)\n";
        cin >> choice;  //NOTE: bug occurs where if you input more than once you move further than expected. Fix this.

                /* generate secret number between 1 and 4. Put in loop to change number generations. */



    bool enemymove = false;
        while (!(enemymove))
        {
            int number = rand() % 4 + 1;

            switch (number)
            {
            case 1: //left
                if (e1col - 1 <= -1 || board[e1row][e1col - 1] == 'X' || e1col - 1 <= -1 || board[e1row][e1col - 1] == 'T')
                {
                    number = rand() % 4 + 1;
                    break;
                }

                else
                {
                    board[e1row][e1col] = '.';
                    e1col -= 1;
                    enemymove = true;
                }

                if (board[e1row][e1col] == 'G')
                {
                     board[e1row][e1col] = 'T';
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else {
                    board[e1row][e1col] = 'T';
                }
                break;

            case 2: //right
                if (e1col + 1 >= 9 || board[e1row][e1col + 1] == 'X' || board[e1row][e1col + 1] == 'T')
                {
                    number = rand() % 4 + 1;
                    break;
                }

                else
                {
                    board[e1row][e1col] = '.';
                    e1col += 1;
                    enemymove = true;
                }

                if (board[e1row][e1col] == 'G')
                {
                    board[e1row][e1col] = 'T';
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else {
                    board[e1row][e1col] = 'T';
                }
                break;

            case 3: //up
                if (e1row - 1 <= -1 || board[e1row- 1][e1col ] == 'X' || board[e1row - 1][e1col] == 'T')
                {
                    number = rand() % 4 + 1;
                    break;
                }

                else
                {
                    board[e1row][e1col] = '.';
                    e1row -= 1;
                    enemymove = true;
                }

                if (board[e1row][e1col] == 'G')
                {
                     board[e1row][e1col] = 'T';
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else {
                    board[e1row][e1col] = 'T';
                }
                break;

            case 4: //down
                if (e1row + 1 >= 9 || board[e1row + 1][e1col] == 'X' || board[e1row + 1][e1col] == 'T')
                {
                    number = rand() % 4 + 1;
                    break;
                }

                else
                {
                    board[e1row][e1col] = '.';
                    e1row += 1;
                    enemymove = true;
                }

                if (board[e1row][e1col] == 'G')
                {
                     board[e1row][e1col] = 'T';
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else {
                    board[e1row][e1col] = 'T';
                }
                break;
            }
        }




        switch (choice)
        {
            // player move
        case 'l' : case 'L':

                if (playercol - 1 <= -1)
                {
                    cout << "You can't go out of bounds. Try again\n";
                }

                else
                {
                    board[playerrow][playercol] = '.';
                    playercol -= 1;
                }

                if (board[playerrow][playercol] == 'T')
                {
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else if (board[playerrow][playercol] == 'X')
                {
                    board[playerrow][playercol] = 'G';
                    system("CLS");
                    DisplayBoard (board);

                    cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
                    gameover = true;
                }

                else {
                    board[playerrow][playercol] = 'G';
                }



            break;

        case 'r': case 'R':
                if (playercol + 1 >= 9)
                {
                    cout << "You can't go out of bounds. Try again\n";
                }

                else
                {
                    board[playerrow][playercol] = '.';
                    playercol += 1;
                }

                if (board[playerrow][playercol] == 'T')
                {
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else if (board[playerrow][playercol] == 'X')
                {
                    board[playerrow][playercol] = 'G';
                    system("CLS");
                    DisplayBoard (board);

                    cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
                    gameover = true;
                }

                else {
                board[playerrow][playercol] = 'G';
                }

            break;

        case 'u': case 'U':
                if (playerrow - 1 <= -1)
                {
                    cout << "You can't go out of bounds. Try again\n";
                }

                else
                {
                    board[playerrow][playercol] = '.';
                    playerrow -= 1;
                }

                if (board[playerrow][playercol] == 'T')
                {
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else if (board[playerrow][playercol] == 'X')
                {
                    board[playerrow][playercol ] = 'G';
                    system("CLS");
                    DisplayBoard (board);
                    cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
                    gameover = true;
                }

                else
                {
                    board[playerrow][playercol] = 'G';
                }

            break;

        case 'd': case 'D':
                if (playerrow + 1 >= 9)
                {
                    cout << "You can't go out of bounds. Try again\n";
                }

                else
                {
                    board[playerrow][playercol] = '.';
                    playerrow += 1;
                }

                if (board[playerrow][playercol] == 'T')
                {
                    system("CLS");
                    DisplayBoard (board);
                    cout << "You have been caught!.\n\nGAME OVER!";
                    gameover = true;
                }

                else if (board[playerrow][playercol] == 'X')
                {
                    board[playerrow][playercol ] = 'G';
                    system("CLS");
                    DisplayBoard (board);
                    cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
                    gameover = true;
                }

                else
                {
                    board[playerrow][playercol] = 'G';

                }

            break;

        default :
            cerr << "ERROR\n\n";
            return -1; //signals that an error occurred.
        }


        turncount++;
    }
}

void DisplayBoard (char grid[9][9])
{
            for (int x = 0; x < 9; x++) //rows
        {
            for (int y = 0; y < 9; y++) //columns
            {
                cout << ' ' << grid[x][y] << ' ';
            }
            cout << endl;
        }
}

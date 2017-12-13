//Author:BYOA
//Program: MonsterGame



#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "monstergame.h"




using namespace std;

int main ()
{
    srand (time(NULL));/* initialize random seed for enemy movement */

    char board[ROWSIZE][COLUMNSIZE];
    initializeGrid (board);

    Move treasure = {8, 8, treasuretype};
    initalizeType (board, treasure);

    Move player = {1, 1, playertype};
    initalizeType (board, player);

    Move enemy1 = {4, 6, enemytype};
    initalizeType (board, enemy1);

    Move enemy2 = {6, 2, enemytype};
    initalizeType (board, enemy2);

    Move enemy3 = {3, 4, enemytype};
    initalizeType (board, enemy3);


    IntroScreen();


    bool gameover = 0; //intialized as false
    int turncount;

    while (!(gameover)) //while gameover is not true (i.ie if false the loop is still true and will re-iterate
    {
        system("CLS");
        DisplayGrid (board);
        cout << "Turn " << ++turncount << endl;

        EnemyMove (board, enemy1);
        EnemyMove (board, enemy2);
        EnemyMove (board, enemy3);

        gameover = EnemyMoveCheck (board, enemy1);
        if (!(gameover))
        gameover = EnemyMoveCheck (board, enemy2);
        if (!(gameover))
        gameover = EnemyMoveCheck (board, enemy3);



    if (!(gameover)) //an if-statement is needed to ensure that if an enemy results in a game-over, the player cannot make a move.
        {
            PlayerMove (board, player);
            gameover = PlayerMoveCheck (board, player);
        }


    }
    cout << "\n\n\nGame span: " << turncount << " turns.";
    return 0;
}

void EnemyMove(char grid[ROWSIZE][COLUMNSIZE], Move &e)
{
    int number = rand() % 4 + 1; //number generation between 1 to 4.
    switch(number)
    {
    case 1://move left
        if ((e.column -1 <= bordermin) || (grid[e.row][e.column -1] == treasuretype) || (grid[e.row][e.column-1] == enemytype))
        {
            EnemyMove (grid, e);
        }
        else
        {
            grid [e.row][e.column] = DisplayChar;
            e.column -= 1;
        }
        break;

    case 2://move right
        if ((e.column + 1 >= bordermax) || (grid[e.row][e.column+ 1] == treasuretype) || (grid[e.row][e.column+1] == enemytype))
        {
            EnemyMove (grid, e);  //recursion
        }
        else
        {
            grid [e.row][e.column] = DisplayChar;
            e.column += 1;
        }
        break;

    case 3://move up
        if ((e.row - 1 <= bordermin) || (grid[e.row- 1][e.column] == treasuretype) || (grid[e.row- 1][e.column] == enemytype))
        {
            EnemyMove (grid, e);  //recursion
        }
        else
        {
            grid [e.row][e.column] = DisplayChar;
            e.row-= 1;
        }

        break;

    case 4://move down
        if ((e.row + 1 >= bordermax) || (grid[e.row+ 1][e.column] == treasuretype) || (grid[e.row+ 1][e.column] == enemytype))
        {
            EnemyMove (grid, e);  //recursion
        }
        else
        {
            grid [e.row][e.column] = DisplayChar;
            e.row+= 1;
        }
        break;
    }
}
bool EnemyMoveCheck (char grid[ROWSIZE][COLUMNSIZE],  Move e)
{
     if (grid [e.row][e.column] == playertype)
        {
            grid [e.row][e.column] = e.type;
            system("CLS");
            DisplayGrid (grid);
            cout << "You have been caught (on the enemy's turn)!.\n\nGAME OVER!";
            return true;
        }
    else
        {
            grid [e.row][e.column] = e.type;
            return false;
        }
}
void PlayerMove (char grid[ROWSIZE][COLUMNSIZE], Move &p)
{
    char choice;
    cout << "Which way will you move? (use WASD keys to move)\n";
    cin >> choice;

      switch(choice)
    {
    case 'a': case 'A'://move left
        if ((p.column - 1 <= bordermin)) //if/else choice instead of while loop as while loop causes to include else statement
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p.row][p.column] = DisplayChar;
            p.column-= 1;
        }
        break;

    case 'd': case 'D'://move right
        if ((p.column + 1 >= bordermax))
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p.row][p.column] = DisplayChar;
            p.column+= 1;
        }
        break;

    case 'w': case 'W'://move up
        if ((p.row - 1 <= bordermin))
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p.row][p.column] = DisplayChar;
            p.row-= 1;
        }
        break;

    case 's': case 'S'://move down
        if ((p.row + 1 >= bordermax))
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p.row][p.column] = DisplayChar;
            p.row += 1;
        }
        break;
    }
}

bool PlayerMoveCheck ( char grid[ROWSIZE][COLUMNSIZE], Move p)

{
        if (grid [p.row][p.column] == enemytype)
        {
            grid [p.row][p.column] = enemytype;
            system("CLS");
            DisplayGrid (grid);
            cout << "You have been caught (on player's turn)!.\n\nGAME OVER!";
            return true;
        }
        else if (grid [p.row][p.column]== treasuretype)
        {
            grid [p.row][p.column] = p.type;
            system("CLS");
            DisplayGrid (grid);
            cout << "Congratulations! You got the treaure (on player side)! \n\nYOU WIN!";
            return true;
        }
        else
        {
            grid [p.row][p.column] = p.type;
            return false;
        }

}
void initializeGrid (char grid[ROWSIZE][COLUMNSIZE])
{
    for (int x = 0; x < ROWSIZE; x++)
    {
        for (int y = 0; y < COLUMNSIZE; y++)
        {
            grid[x][y] = DisplayChar;
        }
    }
}

void initalizeType (char grid[ROWSIZE][COLUMNSIZE], Move typeref)
{
    grid[typeref.row][typeref.column] = typeref.type;
}

void DisplayGrid (char grid[ROWSIZE][COLUMNSIZE])
{
        for (int x = 0; x < ROWSIZE; x++)
    {
        for (int y = 0; y < COLUMNSIZE; y++)
        {
            cout << ' ' << grid [x][y] << ' ';
        }
        cout << '\n';
    }
}

void IntroScreen ()
{
    cout << "                               MONSTER GAME -- BYOA\n\n\n\n";
    cout << "Monster Game premise is to get to the treasure (marked '"<<treasuretype << "') but don't get caught by ";
    cout << "the enemies! (marked '"<< enemytype << "')\n";
    cout << "You are able to move using the WASD keys.\n";
    cout << "You control '" << playertype << "'. Good luck! Don't get caught!!!\n";
    cin.ignore();

}

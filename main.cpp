//Author: BYOA
//Program Name: MonsterGame
//Version 3.0
/*Program:
structure changes value via passing by address. This is because passing pointers will refer to the actual value to be changed,
just like arrays (arrays are implicity converted to pointers; that's why they change the actual value).
*/
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

struct move { //using a structure to define character type and the placement on the board.
    int x; //rows
    int y; //columns
    char type;
};

typedef struct move Move;  //structure alias.

using namespace std;

/*object.member
pointer->member
for structures and classes*/

constexpr int GRIDSIZE = 9;


void DisplayBoard (char grid[GRIDSIZE][GRIDSIZE]);

void PlayerMove (char grid[GRIDSIZE][GRIDSIZE],  Move *p);
bool PlayerMoveCheck ( char grid[GRIDSIZE][GRIDSIZE], Move *p);

void EnemyMove (char grid[GRIDSIZE][GRIDSIZE],  Move *e);
bool EnemyMoveCheck (char grid[GRIDSIZE][GRIDSIZE],  Move *e);



int main ()
{

  srand (time(NULL));/* initialize random seed for enemy movement */

    char board[GRIDSIZE][GRIDSIZE];
    Move treasure = {8, 8, 'X'};
    Move player = {1, 1, 'G'};
    Move enemy1 = {4, 6, 'T'};
    Move enemy2 = {6, 2, 'T'};
    Move enemy3 = {3, 4, 'T'};

    Move *e1ptr = &enemy1;
    Move *e2ptr = &enemy2;
    Move *e3ptr = &enemy3;
    Move *pptr = &player;

    //intitalising board with '.' value.
    for (int x = 0; x < GRIDSIZE; x++)
    {
        for (int y = 0; y < GRIDSIZE; y++)
        {
            board[x][y] = '.';

            if (board [x][y] == board[treasure.x][treasure.y])
                board [x][y] = treasure.type;

            else if (board[x][y] == board[player.x][player.y])
                board [x][y] = player.type;

            else if (board[x][y] == board[enemy1.x][enemy1.y])
                board [x][y] = enemy1.type;

            else if (board[x][y] == board[enemy2.x][enemy2.y])
                board [x][y] = enemy2.type;

            else if (board[x][y] == board[enemy3.x][enemy3.y])
                board [x][y] = enemy3.type;
                /*note: putting board[x][y] as an else statement instead of at top causes errors with enemy3 strut. */
        }
    }

    cout << "                               MONSTER GAME -- BYOA\n\n\n\n";
    cout << "Monster Game premise is to get to the treasure (marked 'X') but don't get caught by enemies! ('T')\n";
    cout << "You are able to move using the WASD keys.\n";
    cout << "You control 'G'. Good luck! Don't get caught!!!\n";
    cin.ignore();
    system("CLS");

    bool gameover = 0; //false
    int turncount = 0;
    while (!(gameover))
    {
 //pointer delcaration and initalization


    system("CLS");
    DisplayBoard (board);
    cout << "Turn " << ++turncount << endl;

    //Enemy move.
    EnemyMove (board, e1ptr);
    EnemyMove (board, e2ptr);
    EnemyMove (board, e3ptr);
    gameover = EnemyMoveCheck (board, e1ptr);
    gameover = EnemyMoveCheck (board, e2ptr);
    gameover = EnemyMoveCheck (board, e3ptr);

    //Playermove
    if (!(gameover)) //an if-statement is needed to ensure that if an enemy results in a game-over, the player cannot make a move.
        {
            PlayerMove (board, pptr);
            gameover = PlayerMoveCheck (board, pptr);
        }
    }
//once loop is false via gameover = true, turn summary occurs.
    cout << "\n\n\nGame span: " << turncount << " turns.";
    return 0;
}





void DisplayBoard (char grid[GRIDSIZE][GRIDSIZE])
{
            for (int x = 0; x < GRIDSIZE; x++) //rows
        {
            for (int y = 0; y < GRIDSIZE; y++) //columns
            {
                cout << ' ' << grid[x][y] << ' ';
            }
            cout << endl;
        }
}

bool PlayerMoveCheck ( char grid[GRIDSIZE][GRIDSIZE], Move *p)
{
        if (grid [p->x][p->y] == 'T')
        {
            grid [p->x][p->y] = 'T';
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught (on player's turn)!.\n\nGAME OVER!";
            return true;
        }
        else if (grid [p->x][p->y] == 'X')
        {
            grid [p->x][p->y] = p->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "Congratulations! You got the treaure (on player side)! \n\nYOU WIN!";
            return true;
        }
        else
        {
            grid [p->x][p->y] = p->type;
            return false;
        }

}

void PlayerMove (char grid[GRIDSIZE][GRIDSIZE],  Move *p)
{
    char choice;
    cout << "Which way will you move? (use WASD keys to move)\n";
    cin >> choice;

      switch(choice)
    {
    case 'a': case 'A'://move left
        if ((p->y - 1 <= -1)) //if/else choice instead of while loop as while loop causes to include else statement
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p->x][p->y] = '.';
            p->y-= 1;
        }
        break;

    case 'd': case 'D'://move right
        if ((p->y + 1 >= 9))
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p->x][p->y] = '.';
            p->y+= 1;
        }
        break;

    case 'w': case 'W'://move up
        if ((p->x - 1 <= -1))
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p->x][p->y] = '.';
            p->x-= 1;
        }
        break;

    case 's': case 'S'://move down
        if ((p->x + 1 >= 9))
        {
            cout << "Wrong choice, try again!.\n";
            PlayerMove (grid, p); //recursion
        }
        else
        {
            grid [p->x][p->y] = '.';
            p->x += 1;
        }
        break;
    }

}
bool EnemyMoveCheck (char grid[GRIDSIZE][GRIDSIZE],  Move *e)
{
     if (grid [e->x][e->y] == 'G')
        {
            grid [e->x][e->y] = e->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught (on the enemy's turn)!.\n\nGAME OVER!";
            return true;
        }
    else
        {
            grid [e->x][e->y] = e->type;
            return false;

        }
}
void EnemyMove (char grid[GRIDSIZE][GRIDSIZE],  Move *e)
{
    int number = rand() % 4 + 1; //number generation between 1 to 4.

    switch(number)
    {
    case 1://move left
        if ((e->y - 1 <= -1) || (grid[e->x][e->y - 1] == 'X') || (grid[e->x][e->y - 1] == 'T'))
        {
            EnemyMove (grid, e);
        }
        else
        {
            grid [e->x][e->y] = '.';
            e->y-= 1;
        }
        break;

    case 2://move right
        if ((e->y + 1 >= 9) || (grid[e->x][e->y + 1] == 'X') || (grid[e->x][e->y + 1] == 'T'))
        {
            EnemyMove (grid, e);  //recursion
        }
        else
        {
            grid [e->x][e->y] = '.';
            e->y+= 1;
        }
        break;

    case 3://move up
        if ((e->x - 1 <= -1) || (grid[e->x- 1][e->y] == 'X') || (grid[e->x- 1][e->y ] == 'T'))
        {
            EnemyMove (grid, e);  //recursion
        }
        else
        {
            grid [e->x][e->y] = '.';
            e->x-= 1;
        }

        break;

    case 4://move down
        if ((e->x + 1 >= 9) || (grid[e->x+ 1][e->y ] == 'X') || (grid[e->x+ 1][e->y ] == 'T'))
        {
            EnemyMove (grid, e);  //recursion
        }
        else
        {
        grid [e->x][e->y] = '.';
        e->x += 1;
        }
        break;
    }
}

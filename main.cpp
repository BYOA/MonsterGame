//Author: BYOA
//Program Name: MonsterGame
//Version 2.0
/*Program:
structure changes value via passing by reference. This is because passing pointers will refer to the actual value to be changed,
just like arrays (arrays are implicity converted to pointers; that's why they change the actual value).
*/
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

struct move { //using a structure to define character type and the placement on the board.
    int x;
    int y;
    char type;
};

typedef struct move Move;  //structure alias.

using namespace std;

/*object.member
pointer->member 
for structures and classes*/

constexpr int GRIDSIZE = 9;

void DisplayBoard (char grid[GRIDSIZE][GRIDSIZE]);
bool PlayerMove (char grid[GRIDSIZE][GRIDSIZE],  Move *p);
bool EnemyMove (char grid[GRIDSIZE][GRIDSIZE],  Move *e);


/*For testing.
1. Add user input conditions to ensure the user cannot break the game. 
2. minimise magic literals. i.e clean up code for version 3.
3. Add final touches to create more user friendliness.
4. Think like and end-user and what they would do. What are any mistakes or inputs they would make? What should I make clear to the user?
3. Think of any further ways to simplify code.
4. Maybe it is possible to use an enumeration data type?
*/

int main ()
{

  srand (time(NULL));/* initialize random seed for enemy movement */
    
    char board[GRIDSIZE][GRIDSIZE];
    Move treasure = {8, 8, 'X'};
    Move player = {1, 1, 'G'};
    Move enemy1 = {4, 6, 'T'};
    Move enemy2 = {6, 2, 'T'};
    Move enemy3 = {3, 4, 'T'};

    
    
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
    Move *e1ptr = &enemy1;
    Move *e2ptr = &enemy2;
    Move *e3ptr = &enemy3;
    Move *pptr = &player;

    system("CLS");
    DisplayBoard (board);
    cout << "Turn " << ++turncount << endl;

    //Enemy move.
    gameover = EnemyMove (board, e1ptr);
    gameover = EnemyMove (board, e2ptr);
    gameover = EnemyMove (board, e3ptr);

    //Playermove
    gameover = PlayerMove (board, pptr);
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


bool PlayerMove (char grid[GRIDSIZE][GRIDSIZE],  Move *p)
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

        if (grid [p->x][p->y] == 'T')
        {
            grid [p->x][p->y] = 'T';
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
        else if (grid [p->x][p->y] == 'X')
        {
            grid [p->x][p->y] = p->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
            return true;
        }
        else
            grid [p->x][p->y] = p->type;
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

        if (grid [p->x][p->y] == 'T')
        {
            grid [p->x][p->y] = 'T';
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
        else if (grid [p->x][p->y] == 'X')
        {
            grid [p->x][p->y] = p->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
            return true;
        }
        else
            grid [p->x][p->y] = p->type;
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

        if (grid [p->x][p->y] == 'T')
        {
            grid [p->x][p->y] = 'T';
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
         else if (grid [p->x][p->y] == 'X')
        {
            grid [p->x][p->y] = p->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
            return true;
        }
        else
            grid [p->x][p->y] = p->type;
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

        if (grid [p->x][p->y] == 'T')
        {
            grid [p->x][p->y] = 'T';
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
        else if (grid [p->x][p->y] == 'X')
        {
            grid [p->x][p->y] = p->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "Congratulations! You got the treaure! \n\nYOU WIN!";
            return true;
        }
        else
            grid [p->x][p->y] = p->type;
        break;
    }

    return false; // game still continues if return false.
}

bool EnemyMove (char grid[GRIDSIZE][GRIDSIZE],  Move *e)
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


        if (grid [e->x][e->y] == 'G')
        {
            grid [e->x][e->y] = e->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
        else
            grid [e->x][e->y] = e->type;
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

        if (grid [e->x][e->y] == 'G')
        {
            grid [e->x][e->y] = e->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
        else
            grid [e->x][e->y] = e->type;
        break;

    case 3://move up
        if ((e->x - 1 <= -1) || (grid[e->x- 1][e->y ] == 'X') || (grid[e->x- 1][e->y ] == 'T'))
        {
            EnemyMove (grid, e);  //recursion
        }
        else
        {
            grid [e->x][e->y] = '.';
            e->x-= 1;
        }

        if (grid [e->x][e->y] == 'G')
        {
            grid [e->x][e->y] = e->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
        else
            grid [e->x][e->y] = e->type;
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

        if (grid [e->x][e->y] == 'G')
        {
            grid [e->x][e->y] = e->type;
            system("CLS");
            DisplayBoard (grid);
            cout << "You have been caught!.\n\nGAME OVER!";
            return true;
        }
        else
            grid [e->x][e->y] = e->type;
        break;
    }

    return false; //return false results in game being continued.
}


struct movement { //using a structure to define character type and the placement on the board.
    int row; //rows
    int column; //columns
    char type;
};
typedef struct movement Move;  //structure alias.

/*Global Constant variables*/
constexpr int ROWSIZE = 9;
constexpr int COLUMNSIZE = 9;

constexpr int bordermin = -1;
constexpr int bordermax = 9;

constexpr char DisplayChar= '.';
constexpr char enemytype = 'T';
constexpr char playertype ='G';
constexpr char treasuretype = 'X';


/*function prototypes*/
void IntroScreen ();
void initializeGrid (char grid[ROWSIZE][COLUMNSIZE]);
void initalizeType (char grid[ROWSIZE][COLUMNSIZE], Move typeref);

void DisplayGrid (char grid[ROWSIZE][COLUMNSIZE]);

void EnemyMove(char grid[ROWSIZE][COLUMNSIZE], Move &e);
void PlayerMove (char grid[ROWSIZE][COLUMNSIZE], Move &p);

bool EnemyMoveCheck (char grid[ROWSIZE][COLUMNSIZE],  Move e);
bool PlayerMoveCheck (char grid[ROWSIZE][COLUMNSIZE],  Move p);


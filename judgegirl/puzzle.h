#include<stdio.h>

typedef struct Puzzle Puzzle;
struct Puzzle{
    int a[4][4];
    int x, y;
};
 
void initPuzzle(Puzzle *puzzle, int grid[4][4]);
void movePiece(Puzzle *puzzle, char direction);

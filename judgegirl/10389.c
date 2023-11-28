#include <stdio.h>
#include <stdlib.h>
#include "puzzle.h"

int ono() {
	//exit(0);
	return 0;
}
void initPuzzle(Puzzle *puzzle, int grid[4][4]) {
	for(int z=0;z<16;z++) {
		int i=z/4, j=z%4;
		(*puzzle).a[i][j]=grid[i][j];
		(grid[i][j]==0&&((*puzzle).x=i));
		(grid[i][j]==0&&((*puzzle).y=j));
	}
}

void movePiece(Puzzle *puzzle, char direction) {
	int rx, ry;
	rx=(((*puzzle).x-1)*(direction=='U')+((*puzzle).x+1)*(direction=='D')+((*puzzle).x*(direction=='L' || direction=='R')));
	ry=(((*puzzle).y-1)*(direction=='L')+((*puzzle).y+1)*(direction=='R')+((*puzzle).y*(direction=='U' || direction=='D')));
	((rx>=4 || ry>=4 || rx<0 || ry<0)&&(printf("Invalid move\n")));
	if(rx>=4 || ry>=4 || rx<0 || ry<0) return;
	int tmpa=(*puzzle).a[(*puzzle).x][(*puzzle).y], tmpb=(*puzzle).a[rx][ry];
	(*puzzle).a[(*puzzle).x][(*puzzle).y]=tmpb;
	(*puzzle).a[rx][ry]=tmpa;
	(*puzzle).x=rx;
	(*puzzle).y=ry;
	for(int i=0;i<16;i++) {
		printf("%d ", (*puzzle).a[i/4][i%4]);
		(i%4==3)&&(printf("\n"));
	}
}
 
/*int main(void) {
    int grid[4][4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    Puzzle puzzle;
    initPuzzle(&puzzle, grid);
    int numMoves;
    scanf("%d", &numMoves);
    char move;
    for (int i = 0; i < numMoves; i++) {
        scanf(" %c", &move);
        movePiece(&puzzle, move);
    }
    return 0;
}*/

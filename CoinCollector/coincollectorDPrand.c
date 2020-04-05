#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 1400
#define COLUMNS 1400
/*
prototipo della funzione max
Parametri:
	unsigned int a: primo numero da confrontare
	unsigned int b: secondo numero da confrontare
Uscita:
	unsigned int: restituisce il maggiore tra a e b*/
unsigned int max(unsigned int a,unsigned int b);
/*
prototipo della funzione bestValue
Parametri:
	unsigned int a:matrice di numeri naturali da esaminare ROWSxCOLUMNS
	size_t x: coordinata x della sottomatrice da esaminare
	size_t y: coordinata y della sottomatrice da esaminare */
unsigned int bestValue (unsigned int a[ROWS][COLUMNS],size_t x, size_t y);

/*prototipo della funzione printArray
Parametri:
	unsigned int a:matrice di numeri naturali da esaminare ROWSxCOLUMNS*/
void printArray(unsigned int a[ROWS][COLUMNS]);
/* 
prototipo della funzione printPath
Parametri:
        unsigned int a:matrice di numeri naturali da esaminare ROWSxCOLUMNS */
void printPath (unsigned int a[ROWS][COLUMNS]);

unsigned int DPValues[ROWS][COLUMNS] = {{0}};

int main () {
	srand(time(NULL));
	unsigned int a[ROWS][COLUMNS];// = {{1, 2, 3}, {7, 6, 12}, {8, 5, 4}};
	for (int i=0;i<ROWS;i++) for (int j=0;j<ROWS;j++) a[i][j]=(rand() % 99)+1;
	puts("\nLa matrice in cui ricercare il percorso più vantaggioso è:\n");
	printArray(a);
	printf ("\nIl bottino totale è: %d\n",bestValue(a,0,0));
	printPath (a);
	return 0;
}

unsigned int bestValue (unsigned int a[ROWS][COLUMNS],size_t x, size_t y) {
	if (!DPValues[y][x]) {
		DPValues[y][x]=a[y][x];
		//CASO BASE: se la matrice da esaminare è monodimensionale
		if (x == COLUMNS-1) for (size_t i=y+1;i<ROWS;i++) DPValues[y][x]+=a[i][x];
		else if (y == ROWS-1) for (size_t i=x+1;i<COLUMNS;i++) DPValues[y][x]+=a[y][i];
		//RICORSIONE
		else DPValues[y][x]+=max(bestValue(a,x+1,y),bestValue(a,x,y+1));
	}
	return DPValues[y][x];
}

void printArray(unsigned int a[ROWS][COLUMNS]){
    for(size_t i = 0; i < ROWS; i++)
    {
        for(size_t j = 0; j < COLUMNS; j++) printf("%3d", a[i][j]);
        puts("");
    }
}

void printPath (unsigned int a[ROWS][COLUMNS]) {
	size_t x=0,y=0;
	printf("Il percorso ottimale è:\n%3d",a[0][0]);
	for (size_t i=0;i<(ROWS+COLUMNS-3);i++) {
		if ((DPValues[y][x]-a[y][x])==DPValues[y+1][x]) y++;
		else x++;
		printf("%3d",a[y][x]);
	}
	printf ("%3d\n\n",a[ROWS-1][COLUMNS-1]);
}

unsigned int max (unsigned int a, unsigned int b) {
	return (a>b)?a:b;
}

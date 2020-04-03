#include<stdio.h>
#define ROWS 3
#define COLUMNS 3
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
        unsigned int a:matrice di numeri naturali da esaminare ROWSxCOLUMNS
	unsigned int total: Massimo guadagno */
void printPath (unsigned int a[ROWS][COLUMNS],unsigned int total);

int main () {
	unsigned int a[ROWS][COLUMNS] = {{1, 2, 3}, {7, 6, 12}, {8, 5, 4}};
	puts("\nLa matrice in cui ricercare il percorso più vantaggioso è:\n");
	printArray(a);
	printf ("\nIl bottino totale è: %d\n",bestValue(a,0,0));
	printPath (a,bestValue(a,0,0)); 
	return 0;
}

unsigned int bestValue (unsigned int a[ROWS][COLUMNS],size_t x, size_t y) {
	unsigned int total=a[y][x];
	//CASO BASE: se la matrice da esaminare è monodimensionale
	if (x == COLUMNS-1) for (size_t i=y+1;i<ROWS;i++) total+=a[i][x];
	else if (y == ROWS-1) for (size_t i=x+1;i<COLUMNS;i++) total+=a[y][i];
	//RICORSIONE
	else total+=(bestValue(a,(x+1),y))>=(bestValue(a,x,(y+1)))?bestValue(a,x+1,y):bestValue(a,x,y+1);
	return total;
}

void printArray(unsigned int a[ROWS][COLUMNS]){
    for(size_t i = 0; i < ROWS; i++)
    {
        for(size_t j = 0; j < COLUMNS; j++) printf("%3d", a[i][j]);
        puts("");
    }
}

void printPath (unsigned int a[ROWS][COLUMNS],unsigned int total) {
	int x=0,y=0;
	printf("Il percorso ottimale è: %d-",a[0][0]);
	for (int i=0;i<(ROWS+COLUMNS-3);i++) {
		if (total-a[y][x]==bestValue(a,x,y+1)) total-=a[y++][x];
		else total-=a[y][x++];
		printf("%d-",a[y][x]);
	}
	printf ("%d\n\n",a[ROWS-1][COLUMNS-1]);
}

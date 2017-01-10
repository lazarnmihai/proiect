#include "stdafx.h"
#include <iostream>
#include "chessHeader.h"

using namespace std;


char tabla[100][100], auxTabla[100][100], sirCaractere[10];
int col[10] = { 1,7,15,23,31,39,47,55,63,69 }, lin[10] = { 1,4,9,14,19,24,29,34,39,43 }, casuta[10][10], aux2[10][10], coordX, coordY, xra, yra, xrn, yrn;


void select(int x, int y)
{
	int c = 254, jndex;
	x--;
	jndex = y - 3;
	for (y = jndex; y < jndex + 7; y++) {
		tabla[x][y] = c;
	}
	y = y - 6;
	x++;
	tabla[x][y] = c;
	y = y + 6;
	tabla[x][y] = c;
	x++;
	y = y - 6;
	tabla[x][y] = c;
	y = y + 6;
	tabla[x][y] = c;
	jndex = y - 6;
	x++;
	for (y = jndex; y < jndex + 7; y++) {
		tabla[x][y] = c;
	}
}

void resetAux()
{
	int ok, x1, index, jndex;
	char charm;
	for (index = 2; index <= 42; index++) {
		if (index == 2 || index == 42) {
			x1 = index;
			strcpy_s(auxTabla[index], "    --------------------------------------------------------------- ");
		}
		else
		{
			if (index - 5 == x1) {
				strcpy_s(auxTabla[index], "   |-------|-------|-------|-------|-------|-------|-------|-------|");
				x1 = index;
			}
			else
			{
				strcpy_s(auxTabla[index], "   |       |       |       |       |       |       |       |       |");
			}
		}
	}
	ok = 1;
	for (index = 1; index <= 8; index++) {
		if (ok == 1) {
			ok = 0;
		}
		else
		{
			ok = 1;
		}
		for (jndex = 1; jndex <= 8; jndex++) {
			if (ok == 1) {
				ok = 0;
			}
			else
			{
				ok = 1;
			}
			if (ok == 1) {
				if (casuta[index][jndex] == 0) {
					casutaAlbann(lin[index], col[jndex]);
				}
				else
				{
					casutaAlbaoo(lin[index], col[jndex]);
				}
			}
		}
	}
	index = lin[0];
	charm = 'A';
	for (jndex = 1; jndex <= 8; jndex++) {
		auxTabla[index][col[jndex]] = charm;
		charm++;
	}
	index = lin[9];
	charm = 'A';
	for (jndex = 1; jndex <= 8; jndex++) {
		auxTabla[index][col[jndex]] = charm;
		charm++;
	}
	jndex = col[0];
	charm = '1';
	for (index = 1; index <= 8; index++) {
		auxTabla[lin[index]][jndex] = charm;
		charm++;
	}
	jndex = col[9];
	charm = '1';
	for (index = 1; index <= 8; index++) {
		auxTabla[lin[index]][jndex] = charm;
		charm++;
	}
}

void deselect(int x, int y)
{
	int c;
	resetAux();
	x--;
	y = y - 2;
	if (auxTabla[x][y] == ' ') {
		c = ' ';
	}
	else
	{
		c = 177;
	}
	y--;
	int jndex = 0;
	jndex = y;
	for (y = jndex; y < jndex + 8; y++) {
		tabla[x][y] = c;
	}
	y = y - 6;
	x++;
	tabla[x][y] = c;
	y = y + 6;
	tabla[x][y] = c;
	x++;
	y = y - 6;
	tabla[x][y] = c;
	y = y + 6;
	tabla[x][y] = c;
	jndex = y - 6;
	x++;
	for (y = jndex; y < jndex + 8; y++) {
		tabla[x][y] = c;
	}
}


void convertire();


void aranjare();


int verificareCoord();


void stergere(int x, int y);


void completareCasute(int x, int y);
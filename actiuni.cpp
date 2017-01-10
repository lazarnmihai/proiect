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

void convertire()
{
	coordX = sirCaractere[0] - 48;
	if (sirCaractere[1] == 'A') {
		coordY = 1;
	}
	if (sirCaractere[1] == 'B') {
		coordY = 2;
	}
	if (sirCaractere[1] == 'C') {
		coordY = 3;
	}
	if (sirCaractere[1] == 'D') {
		coordY = 4;
	}
	if (sirCaractere[1] == 'E') {
		coordY = 5;
	}
	if (sirCaractere[1] == 'F') {
		coordY = 6;
	}
	if (sirCaractere[1] == 'G') {
		coordY = 7;
	}
	if (sirCaractere[1] == 'H') {
		coordY = 8;
	}
}

void aranjare()
{
	char auxSir[3];
	auxSir[0] = 0;
	auxSir[1] = 0;
	if (sirCaractere[0] > '0' && sirCaractere[0] < '9')
	{
		if (sirCaractere[1] > 96 && sirCaractere[1] < 'i')
		{
			if (sirCaractere[1] == 'a') {
				sirCaractere[1] = 'A';
			}
			if (sirCaractere[1] == 'b') {
				sirCaractere[1] = 'B';
			}
			if (sirCaractere[1] == 'c') {
				sirCaractere[1] = 'C';
			}
			if (sirCaractere[1] == 'd') {
				sirCaractere[1] = 'D';
			}
			if (sirCaractere[1] == 'e') {
				sirCaractere[1] = 'E';
			}
			if (sirCaractere[1] == 'f') {
				sirCaractere[1] = 'F';
			}
			if (sirCaractere[1] == 'g') {
				sirCaractere[1] = 'G';
			}
			if (sirCaractere[1] == 'h') {
				sirCaractere[1] = 'H';
			}
		}
	}
	if (sirCaractere[0] > 96 && sirCaractere[0] < 'i')
	{
		if (sirCaractere[0] == 'a') {
			sirCaractere[0] = 'A';
		}
		if (sirCaractere[0] == 'b') {
			sirCaractere[0] = 'B';
		}
		if (sirCaractere[0] == 'c') {
			sirCaractere[0] = 'C';
		}
		if (sirCaractere[0] == 'd') {
			sirCaractere[0] = 'D';
		}
		if (sirCaractere[0] == 'e') {
			sirCaractere[0] = 'E';
		}
		if (sirCaractere[0] == 'f') {
			sirCaractere[0] = 'F';
		}
		if (sirCaractere[0] == 'g') {
			sirCaractere[0] = 'G';
		}
		if (sirCaractere[0] == 'h') {
			sirCaractere[0] = 'H';
		}
		auxSir[1] = sirCaractere[0];
		auxSir[0] = sirCaractere[1];
		sirCaractere[0] = auxSir[0];
		sirCaractere[1] = auxSir[1];
	}
	if (sirCaractere[0] >= 64 && sirCaractere[0] < 'I')
	{
		auxSir[1] = sirCaractere[0];
		auxSir[0] = sirCaractere[1];
		sirCaractere[0] = auxSir[0];
		sirCaractere[1] = auxSir[1];
	}
	convertire();
}

int verificareCoord()
{
	cin >> sirCaractere;
	if (strlen(sirCaractere) == 2)
	{
		if ((sirCaractere[0] > '0' && sirCaractere[0] < '9') || (sirCaractere[0] > 96 && sirCaractere[0] < 'i') || (sirCaractere[0] > 64 && sirCaractere[0] < 'I'))
		{
			if ((sirCaractere[1] > '0' && sirCaractere[1] < '9') || (sirCaractere[1] > 96 && sirCaractere[1] < 'i') || (sirCaractere[1] > 64 && sirCaractere[1] < 'I'))
			{
				if ((sirCaractere[0] > '0' && sirCaractere[0] < '9') && ((sirCaractere[1] > 96 && sirCaractere[1] < 'i') || (sirCaractere[1] >= 64 && sirCaractere[1] < 'I')))
					return 1;
				if ((sirCaractere[1] > '0' && sirCaractere[1] < '9') && ((sirCaractere[0] > 96 && sirCaractere[0] < 'i') || (sirCaractere[0] >= 64 && sirCaractere[0] < 'I')))
					return 1;
				return 0;
			}
			return 0;
		}
		return 0;
	}
	return 0;
}

void stergere(int x, int y)
{
	int ok = 0, index, jndex;
	y = y - 2;
	x--;
	resetAux();
	if (auxTabla[x][y] != ' ') {
		ok = 1;
	}
	y--;
	if (ok == 1) {
		for (index = x; index <= x + 3; index++) {
			for (jndex = y; jndex <= y + 6; jndex++) {
				tabla[index][jndex] = 177;
			}
		}
	}
	else
	{
		for (index = x; index <= x + 3; index++) {
			for (jndex = y; jndex <= y + 6; jndex++) {
				tabla[index][jndex] = ' ';
			}
		}
	}
}

void completareCasute(int x, int y);
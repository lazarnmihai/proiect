#include "stdafx.h"
#include <iostream>
#include "chessHeader.h"

using namespace std;


char tabla[100][100], auxTabla[100][100], sirCaractere[10];
int col[10] = { 1,7,15,23,31,39,47,55,63,69 }, lin[10] = { 1,4,9,14,19,24,29,34,39,43 }, casuta[10][10], aux2[10][10], coordX, coordY, xra, yra, xrn, yrn;


void afisareCasute()
{
	int index, jndex;
	for (index = 0; index < 8; index++) {
		for (jndex = 0; jndex < 8; jndex++)
			cout << casuta[index][jndex] << "  ";
		cout << endl;
	}
}

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

void afisare()
{
	int index, jndex;
	for (index = 0; index <= 45; index++)
	{
		for (jndex = 0; jndex <= 71; jndex++)
			cout << tabla[index][jndex];
		cout << endl;
	}
}

void neg(int x, int y)
{
	x++;
	y--;
	tabla[x][y] = 'N';
	y++;
	tabla[x][y] = 'e';
	y++;
	tabla[x][y] = 'g';
}

void alb(int x, int y)
{
	x++;
	y--;
	tabla[x][y] = 'A';
	y++;
	tabla[x][y] = 'l';
	y++;
	tabla[x][y] = 'b';
}

void casutaAlbao(int x, int y)
{
	int c = 177, jndex;
	x--;
	jndex = y - 3;
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

void casutaAlban(int xx, int yy)
{
	casutaAlbao(xx, yy);
	int jndex;
	jndex = yy - 3;
	int c = 177;
	for (yy = jndex; yy < jndex + 6; yy++) {
		tabla[xx][yy] = c;
	}
	xx++;
	jndex = yy - 4;
	for (yy = jndex; yy < jndex + 6; yy++) {
		tabla[xx][yy] = c;
	}
}

void casutaAlbaoo(int x, int y)
{
	int	c = 177;
	x--;
	int jndex;
	jndex = y - 3;
	for (y = jndex; y < jndex + 8; y++) {
		tabla[x][y] = c;
	}
	y = y - 6;
	x++;
	auxTabla[x][y] = c;
	y = y + 6;
	auxTabla[x][y] = c;
	x++;
	y = y - 6;
	auxTabla[x][y] = c;
	y = y + 6;
	auxTabla[x][y] = c;
	jndex = y - 6;
	x++;
	for (y = jndex; y < jndex + 8; y++) {
		tabla[x][y] = c;
	}
}

void casutaAlbann(int xx, int yy)
{
	casutaAlbaoo(xx, yy);
	char c;
	c = 177;
	int jndex;
	jndex = yy - 3;
	for (yy = jndex; yy < jndex + 6; yy++) {
		tabla[xx][yy] = c;
	}
	xx++;
	jndex = yy - 4;
	for (yy = jndex; yy < jndex + 6; yy++) {
		tabla[xx][yy] = c;
	}
}
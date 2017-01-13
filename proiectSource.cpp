
#include <iostream>
#include <string.h>

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

void completareCasute(int x, int y)
{
	int xx, yy;
	xx = lin[x];
	yy = col[y];
	yy--;
	yy--;
	if (casuta[x][y] == 1) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'P';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		alb(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == 2) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'T';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		alb(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == 3) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'C';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		alb(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == 4) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'N';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		alb(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == 5) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'Q';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		alb(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == 6) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'R';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		alb(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == -1) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'P';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		neg(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == -2) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'T';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		neg(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == -3) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'C';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		neg(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == -4) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'N';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		neg(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == -5) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'Q';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		neg(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
	}

	if (casuta[x][y] == -6) {
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = 'R';
		yy++;
		tabla[xx][yy] = ' ';
		yy++;
		tabla[xx][yy] = ' ';
		yy = yy - 2;
		neg(xx, yy);
		xx++;
		yy = yy - 2;
		tabla[xx][yy] = ' ';
		yy = yy + 4;
		tabla[xx][yy] = ' ';
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



int opuse(int xx1, int yy1, int xx2, int yy2)
{
	if (casuta[xx1][yy1] > 0 && casuta[xx2][yy2] < 0)
		return 1;
	if (casuta[xx1][yy1] < 0 && casuta[xx2][yy2]>0)
		return 1;
	return 0;
}

int mutarePionInvers(int x1, int y1, int x2, int y2)
{
	int x;
	x = x1;
	if (casuta[x2][y2] == 0 && y1 == y2) {
		if (x1 == 7) {
			x1++;
			if (x1 == x2) {
				return 1;
			}
			x1++;
			if (x1 == x2) {
				return 1;
			}
		}
		x1 = x;
		x1++;
		if (x1 == x2) {
			return 1;
		}
	}
	if (casuta[x2][y2] != 0) {
		if (opuse(x1, y1, x2, y2) == 1) {
			x1++;
			y1++;
			if (x1 == x2 && y1 == y2) {
				return 1;
			}
			y1--;
			y1--;
			if (x1 == x2 && y1 == y2) {
				return 1;
			}
		}
	}
	return 0;
}

int mutarePion(int x1, int y1, int x2, int y2)
{
	int x;
	x = x1;
	if (casuta[x2][y2] == 0 && y1 == y2) {
		if (x1 == 7) {
			x1--;
			if (x1 == x2) {
				return 1;
			}
			x1--;
			if (x1 == x2) {
				return 1;
			}
		}
		x1 = x;
		x1--;
		if (x1 == x2) {
			return 1;
		}
	}
	if (casuta[x2][y2] != 0) {
		if (opuse(x1, y1, x2, y2) == 1) {
			x1--;
			y1--;
			if (x1 == x2 && y1 == y2) {
				return 1;
			}
			y1++;
			y1++;
			if (x1 == x2 && y1 == y2) {
				return 1;
			}
		}
	}
	return 0;
}

int mutareTura(int x1, int y1, int x2, int y2)
{
	int index, ok = 1;
	if (casuta[x2][y2] == 0) {
		if (y1 == y2) {
			if (x1 < x2) {
				for (index = x1 + 1; index <= x2; index++) {
					if (casuta[index][y1] != 0) {
						ok = 0;
					}
				}
			}
			else
			{
				for (index = x1 - 1; index >= x2; index--) {
					if (casuta[index][y1] != 0) {
						ok = 0;
					}
				}
			}
			if (ok == 1) {
				return 1;
			}
		}
		if (x1 == x2) {
			if (y1 < y2) {
				for (index = y1 + 1; index <= y2; index++) {
					if (casuta[x1][index] != 0) {
						ok = 0;
					}
				}
			}
			else
			{
				for (index = y1 - 1; index >= y2; index--) {
					if (casuta[x1][index] != 0) {
						ok = 0;
					}
				}
			}
			if (ok == 1) {
				return 1;
			}
		}
	}
	else
	{
		if (opuse(x1, y1, x2, y2) == 1) {
			if (y1 == y2) {
				if (x1 < x2) {
					for (index = x1 + 1; index < x2; index++) {
						if (casuta[index][y1] != 0) {
							ok = 0;
						}
					}
				}
				else
				{
					for (index = x1 - 1; index > x2; index--) {
						if (casuta[index][y1] != 0) {
							ok = 0;
						}
					}
				}
				if (ok == 1) {
					return 1;
				}
			}
			if (x1 == x2) {
				if (y1 < y2) {
					for (index = y1 + 1; index < y2; index++) {
						if (casuta[x1][index] != 0) {
							ok = 0;
						}
					}
				}
				else
				{
					for (index = y1 - 1; index > y2; index--) {
						if (casuta[x1][index] != 0) {
							ok = 0;
						}
					}
				}
				if (ok == 1) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int mutareCal(int x1, int y1, int x2, int y2)
{
	if (casuta[x2][y2] == 0) {
		if (x1 - 2 == x2 && y1 + 1 == y2) {
			return 1;
		}
		if (x1 - 2 == x2 && y1 - 1 == y2) {
			return 1;
		}
		if (x1 + 1 == x2 && y1 - 2 == y2) {
			return 1;
		}
		if (x1 - 1 == x2 && y1 - 2 == y2) {
			return 1;
		}
		if (x1 + 2 == x2 && y1 + 1 == y2) {
			return 1;
		}
		if (x1 + 2 == x2 && y1 - 1 == y2) {
			return 1;
		}
		if (x1 - 1 == x2 && y1 + 2 == y2) {
			return 1;
		}
		if (x1 + 1 == x2 && y1 + 2 == y2) {
			return 1;
		}
	}
	else
	{
		if (opuse(x1, y1, x2, y2) == 1) {
			if (x1 - 2 == x2 && y1 + 1 == y2) {
				return 1;
			}
			if (x1 - 2 == x2 && y1 - 1 == y2) {
				return 1;
			}
			if (x1 + 1 == x2 && y1 - 2 == y2) {
				return 1;
			}
			if (x1 - 1 == x2 && y1 - 2 == y2) {
				return 1;
			}
			if (x1 + 2 == x2 && y1 + 1 == y2) {
				return 1;
			}
			if (x1 + 2 == x2 && y1 - 1 == y2) {
				return 1;
			}
			if (x1 - 1 == x2 && y1 + 2 == y2) {
				return 1;
			}
			if (x1 + 1 == x2 && y1 + 2 == y2) {
				return 1;
			}
		}
	}
}

int mutareNebun(int x1, int y1, int x2, int y2)
{
	int index, jndex, ok;
	if (casuta[x2][y2] == 0) {
		ok = 1;
		index = x1;
		jndex = y1;
		if (x1 > x2 && y1 < y2) {
			while (index > x2 && jndex < y2) {
				index--;
				jndex++;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if ((index == x2 && jndex == y2) && (ok == 1)) {
					return 1;
				}
			}
		}

		index = x1;
		jndex = y1;
		if (x1 < x2 && y1 < y2) {
			while (index < x2 && jndex < y2) {
				index++;
				jndex++;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if ((index == x2 && jndex == y2) && (ok == 1)) {
					return 1;
				}
			}
		}

		index = x1;
		jndex = y1;
		if (x1<x2 && y1>y2) {
			while (index<x2 && jndex>y2) {
				index++;
				jndex--;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if ((index == x2 && jndex == y2) && (ok == 1)) {
					return 1;
				}
			}
		}

		index = x1;
		jndex = y1;
		if (x1 > x2 && y1 > y2) {
			while (index > x2 && jndex > y2) {
				index--;
				jndex--;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if ((index == x2 && jndex == y2) && (ok == 1)) {
					return 1;
				}
			}
		}
	}
	else
	{
		if (opuse(x1, y1, x2, y2) == 1) {
			ok = 1;
			index = x1;
			jndex = y1;
			if (x1 > x2 && y1 < y2) {
				while (index >= x2 && jndex <= y2) {
					index--;
					jndex++;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if ((index == x2 && jndex == y2) && (ok == 1)) {
						return 1;
					}
				}
			}
			index = x1;
			jndex = y1;
			if (x1 < x2 && y1 < y2) {
				while (index <= x2 && jndex <= y2) {
					index++;
					jndex++;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if ((index == x2 && jndex == y2) && (ok == 1)) {
						return 1;
					}
				}
			}
			index = x1;
			jndex = y1;
			if (x1<x2 && y1>y2) {
				while (index <= x2 && jndex >= y2) {
					index++;
					jndex--;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if ((index == x2 && jndex == y2) && (ok == 1)) {
						return 1;
					}
				}
			}
			index = x1;
			jndex = y1;
			if (x1 > x2 && y1 > y2) {
				while (index >= x2 && jndex >= y2) {
					index--;
					jndex--;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if ((index == x2 && jndex == y2) && (ok == 1)) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int mutareRegina(int x1, int y1, int x2, int y2)
{
	int index, jndex, ok = 1;
	if (casuta[x2][y2] == 0) {
		if (y1 == y2) {
			if (x1 < x2) {
				for (index = x1 + 1; index <= x2; index++) {
					if (casuta[index][y1] != 0) {
						ok = 0;
					}
				}
			}
			else
			{
				for (index = x1 - 1; index >= x2; index--) {
					if (casuta[index][y1] != 0) {
						ok = 0;
					}
				}
			}
			if (ok == 1) {
				return 1;
			}
		}
		if (x1 == x2) {
			if (y1 < y2) {
				for (index = y1 + 1; index <= y2; index++) {
					if (casuta[x1][index] != 0) {
						ok = 0;
					}
				}
			}
			else
			{
				for (index = y1 - 1; index >= y2; index--) {
					if (casuta[x1][index] != 0) {
						ok = 0;
					}
				}
			}
			if (ok == 1) {
				return 1;
			}
		}

		ok = 1;
		index = x1;
		jndex = y1;
		if (x1 > x2 && y1 < y2) {
			while (index > x2 && jndex < y2) {
				index--;
				jndex++;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if (index == x2 && jndex == y2) {
					if (ok == 1) {
						return 1;
					}
				}
			}
		}
		index = x1;
		jndex = y1;
		if (x1 < x2 && y1 < y2) {
			while (index < x2 && jndex < y2) {
				index++;
				jndex++;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if (index == x2 && jndex == y2) {
					if (ok == 1) {
						return 1;
					}
				}
			}
		}
		index = x1;
		jndex = y1;
		if (x1<x2 && y1>y2) {
			while (index<x2 && jndex>y2) {
				index++;
				jndex--;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if (index == x2 && jndex == y2) {
					if (ok == 1) {
						return 1;
					}
				}
			}
		}
		index = x1;
		jndex = y1;
		if (x1 > x2 && y1 > y2) {
			while (index > x2 && jndex > y2) {
				index--;
				jndex--;
				if (casuta[index][jndex] != 0) {
					ok = 0;
				}
				if (index == x2 && jndex == y2) {
					if (ok == 1) {
						return 1;
					}
				}
			}
		}
	}
	else
	{
		if (opuse(x1, y1, x2, y2) == 1) {
			if (y1 == y2) {
				if (x1 < x2) {
					for (index = x1 + 1; index < x2; index++) {
						if (casuta[index][y1] != 0) {
							ok = 0;
						}
					}
				}
				else
				{
					for (index = x1 - 1; index > x2; index--) {
						if (casuta[index][y1] != 0) {
							ok = 0;
						}
					}
				}
				if (ok == 1) {
					return 1;
				}
			}
			if (x1 == x2) {
				if (y1 < y2) {
					for (index = y1 + 1; index < y2; index++) {
						if (casuta[x1][index] != 0) {
							ok = 0;
						}
					}
				}
				else
				{
					for (index = y1 - 1; index > y2; index--) {
						if (casuta[x1][index] != 0) {
							ok = 0;
						}
					}
				}
				if (ok == 1) {
					return 1;
				}
			}
			//--------------------------------------------------------------------------------------------
			ok = 1;
			index = x1;
			jndex = y1;
			if (x1 > x2 && y1 < y2) {
				while (index >= x2 && jndex <= y2) {
					index--;
					jndex++;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if (index == x2 && jndex == y2) {
						if (ok == 1) {
							return 1;
						}
					}
				}
			}
			index = x1;
			jndex = y1;
			if (x1 < x2 && y1 < y2) {
				while (index <= x2 && jndex <= y2) {
					index++;
					jndex++;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if (index == x2 && jndex == y2) {
						if (ok == 1) {
							return 1;
						}
					}
				}
			}
			index = x1;
			jndex = y1;
			if (x1<x2 && y1>y2) {
				while (index <= x2 && jndex >= y2) {
					index++;
					jndex--;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if (index == x2 && jndex == y2) {
						if (ok == 1) {
							return 1;
						}
					}
				}
			}
			index = x1;
			jndex = y1;
			if (x1 > x2 && y1 > y2) {
				while (index >= x2 && jndex >= y2) {
					index--;
					jndex--;
					if (casuta[index][jndex] != 0 && index != x2) {
						ok = 0;
					}
					if (index == x2 && jndex == y2) {
						if (ok == 1) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int mutareRege(int x1, int y1, int x2, int y2)
{
	int index, jndex;
	if (casuta[x2][y2] == 0) {
		index = x1;
		jndex = y1;
		index++;
		jndex++;
		if (index == x2 && jndex == y2) {
			return 1;
		}
		index = x1;
		jndex = y1;
		index--;
		jndex++;
		if (index == x2 && jndex == y2) {
			return 1;
		}
		index = x1;
		jndex = y1;
		index++;
		jndex--;
		if (index == x2 && jndex == y2) {
			return 1;
		}
		index = x1;
		jndex = y1;
		index--;
		jndex--;
		if (index == x2 && jndex == y2) {
			return 1;
		}
		index = x1;
		jndex = y1;
		index++;
		if (index == x2 && jndex == y2) {
			return 1;
		}
		index = x1;
		jndex = y1;
		index--;
		if (index == x2 && jndex == y2) {
			return 1;
		}
		index = x1;
		jndex = y1;
		jndex++;
		if (index == x2 && jndex == y2) {
			return 1;
		}
		index = x1;
		jndex = y1;
		jndex--;
		if (index == x2 && jndex == y2) {
			return 1;
		}
	}
	else
	{
		if (opuse(x1, y1, x2, y2) == 1) {
			index = x1;
			jndex = y1;
			index++;
			jndex++;
			if (index == x2 && jndex == y2) {
				return 1;
			}
			index = x1;
			jndex = y1;
			index--;
			jndex++;
			if (index == x2 && jndex == y2) {
				return 1;
			}
			index = x1;
			jndex = y1;
			index++;
			jndex--;
			if (index == x2 && jndex == y2) {
				return 1;
			}
			index = x1;
			jndex = y1;
			index--;
			jndex--;
			if (index == x2 && jndex == y2) {
				return 1;
			}
			index = x1;
			jndex = y1;
			index++;
			if (index == x2 && jndex == y2) {
				return 1;
			}
			index = x1;
			jndex = y1;
			index--;
			if (index == x2 && jndex == y2) {
				return 1;
			}
			index = x1;
			jndex = y1;
			jndex++;
			if (index == x2 && jndex == y2) {
				return 1;
			}
			index = x1;
			jndex = y1;
			jndex--;
			if (index == x2 && jndex == y2) {
				return 1;
			}
		}
	}
	return 0;
}


void schimbarePion(int x1, int y1)
{
	int ok = 0;
	char ch;
	while (ok == 0) {
		cout << "\ \ \ \ Cu ce doriti sa inlocuiti pionul ?(T,C,N,Q):";
		cin >> ch;
		if (ch == 't') {
			ch = 'T';
		}
		if (ch == 'c') {
			ch = 'C';
		}
		if (ch == 'n') {
			ch = 'N';
		}
		if (ch == 'q') {
			ch = 'Q';
		}
		if (ch == 'T') {
			if (casuta[x1][y1] > 0) {
				casuta[x1][y1] = 2;
				completareCasute(x1, y1);
				alb(lin[x1], col[y1]);
				ok = 1;
			}
			if (casuta[x1][y1] < 0) {
				casuta[x1][y1] = -2;
				completareCasute(x1, y1);
				neg(lin[x1], col[y1]);
				ok = 1;
			}
		}
		if (ch == 'C') {
			if (casuta[x1][y1] > 0) {
				casuta[x1][y1] = 3;
				completareCasute(x1, y1);
				alb(lin[x1], col[y1]);
				ok = 1;
			}
			if (casuta[x1][y1] < 0) {
				casuta[x1][y1] = -3;
				completareCasute(x1, y1);
				neg(lin[x1], col[y1]);
				ok = 1;
			}
		}
		if (ch == 'N') {
			if (casuta[x1][y1] > 0) {
				casuta[x1][y1] = 4;
				completareCasute(x1, y1);
				alb(lin[x1], col[y1]);
				ok = 1;
			}
			if (casuta[x1][y1] < 0) {
				casuta[x1][y1] = -4;
				completareCasute(x1, y1);
				neg(lin[x1], col[y1]);
				ok = 1;
			}
		}
		if (ch == 'Q') {
			if (casuta[x1][y1] > 0) {
				casuta[x1][y1] = 5;
				completareCasute(x1, y1);
				alb(lin[x1], col[y1]);
				ok = 1;
			}
			if (casuta[x1][y1] < 0) {
				casuta[x1][y1] = -5;
				completareCasute(x1, y1);
				neg(lin[x1], col[y1]);
				ok = 1;
			}
		}
	}
}

int sah(int xx1, int yy1)
{
	int index, jndex;
	if (casuta[xx1][yy1] > 0) {
		for (index = 1; index <= 8; index++) {
			for (jndex = 1; jndex <= 8; jndex++) {
				if (casuta[index][jndex] < 0) {
					if (casuta[index][jndex] == -1) {
						if (mutarePionInvers(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == -2) {
						if (mutareTura(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == -3) {
						if (mutareCal(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == -4) {
						if (mutareNebun(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == -5) {
						if (mutareRegina(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == -6) {
						if (mutareRege(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
				}
			}
		}
	}
	if (casuta[xx1][yy1] < 0) {
		for (index = 1; index <= 8; index++) {
			for (jndex = 1; jndex <= 8; jndex++) {
				if (casuta[index][jndex] > 0) {
					if (casuta[index][jndex] == 1) {
						if (mutarePionInvers(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == 2) {
						if (mutareTura(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == 3) {
						if (mutareCal(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == 4) {
						if (mutareNebun(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == 5) {
						if (mutareRegina(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
					if (casuta[index][jndex] == 6) {
						if (mutareRege(index, jndex, xx1, yy1) == 1) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int verifRocada(int x1, int y1, int x2, int y2)
{
	if (casuta[x1][y1] > 0) {
		if (x1 == x2) {
			if (casuta[x1][y1] == 6) {
				if (casuta[x2][y2] == 2) {
					if (y2 - y1 == 3) {
						if (casuta[x1][y1 + 1] == 0 && casuta[x1][y1 + 2] == 0) {
							return 1;
						}
					}
					if (y1 - y2 == 4) {
						if (casuta[x1][y1 - 1] == 0 && casuta[x1][y1 - 2] == 0 && casuta[x1][y1 - 3] == 0) {
							return 1;
						}
					}
				}
			}
		}
	}
	if (casuta[x1][y1] < 0) {
		if (x1 == x2) {
			if (casuta[x1][y1] == -6) {
				if (casuta[x2][y2] == -2) {
					if (y1 - y2 == 3) {
						if (casuta[x1][y1 - 1] == 0 && casuta[x1][y1 - 2] == 0) {
							return 1;
						}
					}
					if (y2 - y1 == 4) {
						if (casuta[x1][y1 + 1] == 0 && casuta[x1][y1 + 2] == 0 && casuta[x1][y1 + 3] == 0) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

void rocada(int x1, int y1, int x2, int y2)
{
	if (casuta[x1][y1] > 0) {
		if (x1 == x2) {
			if (casuta[x1][y1] == 6) {
				if (casuta[x2][y2] == 2) {
					if (y2 - y1 == 3) {
						if (casuta[x1][y1 + 1] == 0 && casuta[x1][y1 + 2] == 0) {
							casuta[x1][y1 + 1] = 2;
							casuta[x1][y1 + 2] = 6;
							casuta[x1][y1] = 0;
							casuta[x2][y2] = 0;
							tabla[lin[x1]][col[y1 + 1]] = 'T';
							completareCasute(x1, y1 + 1);
							tabla[lin[x1]][col[y1 + 2]] = 'R';
							completareCasute(x1, y1 + 2);
							stergere(lin[x1], col[y1]);
							stergere(lin[x2], col[y2]);
						}
					}
					if (y1 - y2 == 4) {
						if (casuta[x1][y1 - 1] == 0 && casuta[x1][y1 - 2] == 0 && casuta[x1][y1 - 3] == 0) {
							casuta[x1][y1 - 1] = 2;
							casuta[x1][y1 - 2] = 6;
							casuta[x1][y1] = 0;
							casuta[x2][y2] = 0;
							tabla[lin[x1]][col[y1 - 1]] = 'T';
							completareCasute(x1, y1 - 1);
							tabla[lin[x1]][col[y1 - 2]] = 'R';
							completareCasute(x1, y1 - 2);
							stergere(lin[x1], col[y1]);
							stergere(lin[x2], col[y2]);
						}
					}
				}
			}
		}
	}
	if (casuta[x1][y1] < 0) {
		if (x1 == x2) {
			if (casuta[x1][y1] == -6) {
				if (casuta[x2][y2] == -2) {
					if (y1 - y2 == 3) {
						if (casuta[x1][y1 - 1] == 0 && casuta[x1][y1 - 2] == 0) {
							casuta[x1][y1 - 1] = -2;
							casuta[x1][y1 - 2] = -6;
							casuta[x1][y1] = 0;
							casuta[x2][y2] = 0;
							tabla[lin[x1]][col[y1 - 1]] = 'T';
							completareCasute(x1, y1 - 1);
							tabla[lin[x1]][col[y1 - 2]] = 'R';
							completareCasute(x1, y1 - 2);
							stergere(lin[x1], col[y1]);
							stergere(lin[x2], col[y2]);
						}
					}
					if (y2 - y1 == 4) {
						if (casuta[x1][y1 + 1] == 0 && casuta[x1][y1 + 2] == 0 && casuta[x1][y1 + 3] == 0) {
							casuta[x1][y1 + 1] = -2;
							casuta[x1][y1 + 2] = -6;
							casuta[x1][y1] = 0;
							casuta[x2][y2] = 0;
							tabla[lin[x1]][col[y1 + 1]] = 'T';
							completareCasute(x1, y1 + 1);
							tabla[lin[x1]][col[y1 + 2]] = 'R';
							completareCasute(x1, y1 + 2);
							stergere(lin[x1], col[y1]);
							stergere(lin[x2], col[y2]);
						}
					}
				}
			}
		}
	}
}

int mutare(int cooX1, int cooY1, int cooX2, int cooY2)
{
	if (casuta[cooX1][cooY1] == 1) {
		if (mutarePion(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == 2) {
		if (mutareTura(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == 3) {
		if (mutareCal(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == 4) {
		if (mutareNebun(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == 5) {
		if (mutareRegina(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == 6) {
		if (mutareRege(cooX1, cooY1, cooX2, cooY2) == 1) {
			casuta[cooX2][cooY2] = 6;
			if (sah(cooX2, cooY2) == 0) {
				return 1;
			}
			casuta[cooX2][cooY2] = 0;
		}
		return 0;
	}
	if (casuta[cooX1][cooY1] == -1) {
		if (mutarePion(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == -2) {
		if (mutareTura(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == -3) {
		if (mutareCal(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == -4) {
		if (mutareNebun(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == -5) {
		if (mutareRegina(cooX1, cooY1, cooX2, cooY2) == 1) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (casuta[cooX1][cooY1] == -6) {
		if (mutareRege(cooX1, cooY1, cooX2, cooY2) == 1) {
			casuta[cooX2][cooY2] = -6;
			if (sah(cooX2, cooY2) == 0) {
				return 1;
			}
			casuta[cooX2][cooY2] = 0;
		}
		return 0;
	}
}

int sahMat(int x, int y)
{
	int index, jndex, ok = 1, kndex, hndex, xx, yy, var;
	if (casuta[x][y] > 0) {
		for (index = 1; index <= 8; index++) {
			for (jndex = 1; jndex <= 8; jndex++) {
				for (kndex = 1; kndex <= 8; kndex++) {
					for (hndex = 1; hndex <= 8; hndex++) {
						if (casuta[kndex][hndex] > 0) {
							if (casuta[kndex][hndex] == 1) {
								if (mutarePion(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 1;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = 1;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 2) {
								if (mutareTura(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 2;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = 2;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 3) {
								if (mutareCal(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 3;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = 3;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 4) {
								if (mutareNebun(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 4;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = 4;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 5) {
								if (mutareRegina(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 5;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = 5;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 6) {
								if (mutareRege(kndex, hndex, index, jndex) == 1) {
									xx = index;
									yy = jndex;
									var = casuta[xx][yy];
									casuta[kndex][hndex] = 0;
									casuta[xx][yy] = 6;
									if (sah(xx, yy) == 0) {
										ok = 0;
									}
									casuta[xx][yy] = var;
									casuta[kndex][hndex] = 6;
								}
							}
						}
					}
				}
			}
		}
	}
	if (casuta[x][y] < 0) {
		for (index = 1; index <= 8; index++) {
			for (jndex = 1; jndex <= 8; jndex++) {
				for (kndex = 1; kndex <= 8; kndex++) {
					for (hndex = 1; hndex <= 8; hndex++) {
						if (casuta[kndex][hndex] < 0) {
							if (casuta[kndex][hndex] == -1) {
								if (mutarePion(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -1;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = -1;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -2) {
								if (mutareTura(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -2;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = -2;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -3) {
								if (mutareCal(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -3;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = -3;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -4) {
								if (mutareNebun(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -4;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = -4;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -5) {
								if (mutareRegina(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -5;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 0;
									}
									casuta[kndex][hndex] = -5;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -6) {
								if (mutareRege(kndex, hndex, index, jndex) == 1) {
									xx = index;
									yy = jndex;
									var = casuta[xx][yy];
									casuta[kndex][hndex] = 0;
									casuta[xx][yy] = -6;
									if (sah(xx, yy) == 0) {
										ok = 0;
									}
									casuta[xx][yy] = var;
									casuta[kndex][hndex] = -6;
								}
							}
						}
					}
				}
			}
		}
	}
	if (ok == 1) {
		return 1;
	}
	else
	{
		return 0;
	}
}

int pat(int x, int y)
{
	int index, jndex, kndex, hndex, ok = 0, xx, yy, var;
	if (casuta[x][y] > 0) {
		for (index = 1; index <= 8; index++) {
			for (jndex = 1; jndex <= 8; jndex++) {
				for (kndex = 1; kndex <= 8; kndex++) {
					for (hndex = 1; hndex <= 8; hndex++) {
						if (casuta[kndex][hndex] > 0) {
							if (casuta[kndex][hndex] == 1) {
								if (mutarePion(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 1;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = 1;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 2) {
								if (mutareTura(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 2;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = 2;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 3) {
								if (mutareCal(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 3;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = 3;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 4) {
								if (mutareNebun(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 4;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = 4;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 5) {
								if (mutareRegina(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = 5;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = 5;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == 6) {
								if (mutareRege(kndex, hndex, index, jndex) == 1) {
									xx = index;
									yy = jndex;
									var = casuta[xx][yy];
									casuta[kndex][hndex] = 0;
									casuta[xx][yy] = 6;
									if (sah(xx, yy) == 0) {
										ok = 1;
									}
									casuta[xx][yy] = var;
									casuta[kndex][hndex] = 6;
								}
							}
						}
					}
				}
			}
		}
	}
	if (casuta[x][y] < 0) {
		for (index = 1; index <= 8; index++) {
			for (jndex = 1; jndex <= 8; jndex++) {
				for (kndex = 1; kndex <= 8; kndex++) {
					for (hndex = 1; hndex <= 8; hndex++) {
						if (casuta[kndex][hndex] < 0) {
							if (casuta[kndex][hndex] == -1) {
								if (mutarePion(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -1;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = -1;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -2) {
								if (mutareTura(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -2;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = -2;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -3) {
								if (mutareCal(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -3;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = -3;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -4) {
								if (mutareNebun(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -4;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = -4;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -5) {
								if (mutareRegina(kndex, hndex, index, jndex) == 1) {
									var = casuta[index][jndex];
									casuta[index][jndex] = -5;
									casuta[kndex][hndex] = 0;
									if (sah(x, y) == 0) {
										ok = 1;
									}
									casuta[kndex][hndex] = -5;
									casuta[index][jndex] = var;
								}
							}
							if (casuta[kndex][hndex] == -6) {
								if (mutareRege(kndex, hndex, index, jndex) == 1) {
									xx = index;
									yy = jndex;
									var = casuta[xx][yy];
									casuta[kndex][hndex] = 0;
									casuta[xx][yy] = -6;
									if (sah(xx, yy) == 0) {
										ok = 1;
									}
									casuta[xx][yy] = var;
									casuta[kndex][hndex] = -6;
								}
							}
						}
					}
				}
			}
		}
	}
	if (ok == 1) {
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int index, jndex, ok, x1, x2, y1, y2, albe[4] = { 0,1,1,1 }, negre[4] = { 0,1,1,1 };
	char p1[256], p2[256], charm;
	xra = 8;
	yra = 5;
	xrn = 8;
	yrn = 4;
	cout << endl;
	cout << "\ \ \ \ CHESS";
	cout << endl << endl;
	cout << "\ \ \ \ Jucator 1:"; cin >> p1;
	cout << "\ \ \ \ Jucator 2:"; cin >> p2;
	cout << endl;
	cout << "\ \ \ \ Reguli de joc:";
	cout << endl;
	cout << "\ \ \ * Pentru a efectua o mutare selectati o piesa(ex: A2,d1,etc ).";
	cout << endl;
	cout << "\ \ \ * Apoi introduceti coordonatele casutei unde vreti sa mutati piesa.";
	cout << endl;
	cout << "\ \ \ * Pentru a deselecta o piesa introduceti coordonatele piesei din nou.";
	cout << endl;
	cout << endl;
	cout << "\ \ \ \ Legenda:";
	cout << endl << endl;
	cout << "\ \ \ \ T=tura";
	cout << endl;
	cout << "\ \ \ \ P=pion";
	cout << endl;
	cout << "\ \ \ \ N=nebun";
	cout << endl;
	cout << "\ \ \ \ C=cal";
	cout << endl;
	cout << "\ \ \ \ Q=regina";
	cout << endl;
	cout << "\ \ \ \ R=rege";
	cout << endl << endl;
	cout << "\ \ \ \ Jocul incepe:";
	cout << endl << endl;

	//Test
	index = 2;
	for (jndex = 1; jndex <= 8; jndex++) {
		casuta[index][jndex] = -1;
	}
	index = 7;
	for (jndex = 1; jndex <= 8; jndex++) {
		casuta[index][jndex] = 1;
	}
	x1 = 1;
	x2 = 8;
	y1 = 1;
	y2 = 8;
	casuta[x1][y1] = -2;
	casuta[x1][y2] = -2;
	casuta[x2][y1] = 2;
	casuta[x2][y2] = 2;

	y1 = 2;
	y2 = 7;
	casuta[x1][y1] = -3;
	casuta[x1][y2] = -3;
	casuta[x2][y1] = 3;
	casuta[x2][y2] = 3;

	y1 = 3;
	y2 = 6;
	casuta[x1][y1] = -4;
	casuta[x1][y2] = -4;
	casuta[x2][y1] = 4;
	casuta[x2][y2] = 4;

	y1 = 4;
	y2 = 5;
	casuta[x1][y1] = -5;
	casuta[x1][y2] = -6;
	casuta[x2][y1] = 5;
	casuta[x2][y2] = 6;
	for (index = 2; index <= 42; index++) {
		if (index == 2 || index == 42) {
			x1 = index;
			strcpy_s(tabla[index], "    --------------------------------------------------------------- ");
		}
		else
		{
			if (index - 5 == x1) {
				strcpy_s(tabla[index], "   |-------|-------|-------|-------|-------|-------|-------|-------|");
				x1 = index;
			}
			else
			{
				strcpy_s(tabla[index], "   |       |       |       |       |       |       |       |       |");
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
				casutaAlban(lin[index], col[jndex]);
			}
			else
			{
				casutaAlbao(lin[index], col[jndex]);
			}
		}
	}


	index = lin[0];
	charm = 'A';
	for (jndex = 1; jndex <= 8; jndex++) {
		tabla[index][col[jndex]] = charm;
		charm++;
	}
	index = lin[9];
	charm = 'A';
	for (jndex = 1; jndex <= 8; jndex++) {
		tabla[index][col[jndex]] = charm;
		charm++;
	}
	jndex = col[0];
	charm = '1';
	for (index = 1; index <= 8; index++) {
		tabla[lin[index]][jndex] = charm;
		charm++;
	}
	jndex = col[9];
	charm = '1';
	for (index = 1; index <= 8; index++) {
		tabla[lin[index]][jndex] = charm;
		charm++;
	}

	//Test
	index = lin[2];
	for (jndex = 1; jndex <= 8; jndex++) {
		tabla[index][col[jndex]] = 'P';
		neg(index, col[jndex]);
	}
	index = lin[7];
	for (jndex = 1; jndex <= 8; jndex++) {
		tabla[index][col[jndex]] = 'P';
		alb(index, col[jndex]);
	}

	x1 = lin[1];
	x2 = lin[8];
	y1 = col[1];
	y2 = col[8];
	tabla[x1][y1] = 'T';
	tabla[x1][y2] = 'T';
	tabla[x2][y1] = 'T';
	tabla[x2][y2] = 'T';

	y1 = col[2];
	y2 = col[7];
	tabla[x1][y1] = 'C';
	tabla[x1][y2] = 'C';
	tabla[x2][y1] = 'C';
	tabla[x2][y2] = 'C';

	y1 = col[3];
	y2 = col[6];
	tabla[x1][y1] = 'N';
	tabla[x1][y2] = 'N';
	tabla[x2][y1] = 'N';
	tabla[x2][y2] = 'N';

	y1 = col[4];
	y2 = col[5];
	tabla[x1][y1] = 'Q';
	tabla[x1][y2] = 'R';
	tabla[x2][y1] = 'Q';
	tabla[x2][y2] = 'R';

	index = lin[1];
	for (jndex = 1; jndex <= 8; jndex++) {
		neg(index, col[jndex]);
	}
	index = lin[8];
	for (jndex = 1; jndex <= 8; jndex++) {
		alb(index, col[jndex]);
	}
	//Test

	int sw = 2, okk, xx, yy, okkk, dis, ok10, sahh = 0, v, v2, sm = 0;
	ok = 1;
	while (ok == 1) {
		afisare();
		if (sw == 1) {
			sw = 2;
		}
		else
		{
			sw = 1;
		}
		if (sw == 1) {
			cout << "\ \ \ \ " << p1 << " este randul tau:" << endl;
		}
		else
		{
			cout << "\ \ \ \ " << p2 << " este randul tau:" << endl;
		}
		okk = 0;
		while (okk == 0) {
			if (verificareCoord() == 1) {
				if (sw == 1) {
					aranjare();
					if (casuta[coordX][coordY] > 0) {
						okk = 1;
					}
					else
					{
						cout << "\ \ \ \ Coordonate gresite:";
					}
				}
				else
				{
					aranjare();
					if (casuta[coordX][coordY] < 0) {
						okk = 1;
					}
					else
					{
						cout << "\ \ \ \ Coordonate gresite:";
					}
				}
			}
			else
			{
				cout << "\ \ \ \ Coordonate gresite:";
			}
		}


		okkk = 0;
		select(lin[coordX], col[coordY]);
		xx = coordX;
		yy = coordY;
		dis = 1;
		ok10 = 0;
		while (okkk == 0) {
			afisare();
			if (sahh == 1) {
				cout << "\ \ \ \ Esti in sah. Reincercati:";
			}
			sahh = 0;
			if (dis == 1) {
				xx = coordX;
				yy = coordY;
				cout << "\ \ \ \ Mutare pe coordonatele:";
			}
			if (ok10 == 1 && dis == 0) {
				cout << "\ \ \ \ Mutare nepermisa. Reincercati:";
			}
			dis = 0;
			ok10 = 0;
			if (verificareCoord() == 1) {
				aranjare();
				if (coordX == xx && coordY == yy) {
					dis = 1;
					deselect(lin[coordX], col[coordY]);
					okk = 0;
					afisare();
					cout << "\ \ \ \ Introduceti coordonate noi:";
					while (okk == 0) {
						if (verificareCoord() == 1) {
							if (sw == 1) {
								aranjare();
								if (casuta[coordX][coordY] > 0) {
									okk = 1;
								}
								else
								{
									cout << "\ \ \ \ Coordonate gresite:";
								}
							}
							else
							{
								aranjare();
								if (casuta[coordX][coordY] < 0) {
									okk = 1;
								}
								else
								{
									cout << "\ \ \ \ Coordonate gresite:";
								}
							}
						}
						else
						{
							cout << "\ \ \ \ Coordonate gresite:";
						}
					}
					select(lin[coordX], col[coordY]);
				}
			}
			if (mutare(xx, yy, coordX, coordY) == 1) {
				if (sw == 1) {
					if (xx == 8 && yy == 1) {
						albe[1] = 0;
					}
					if (xx == 8 && yy == 5) {
						albe[2] = 0;
					}
					if (xx == 8 && yy == 8) {
						albe[3] = 0;
					}
				}
				else
				{
					if (xx == 8 && yy == 1) {
						negre[1] = 0;
					}
					if (xx == 8 && yy == 4) {
						negre[2] = 0;
					}
					if (xx == 8 && yy == 8) {
						negre[3] = 0;
					}
				}
				if (casuta[xx][yy] == 6) {
					xra = coordX;
					yra = coordY;
				}
				if (casuta[xx][yy] == -6) {
					xrn = coordX;
					yrn = coordY;
				}
				if (sw == 1) {
					if (sah(xra, yra) == 0) {
						v2 = casuta[coordX][coordY];
						casuta[coordX][coordY] = casuta[xx][yy];
						casuta[xx][yy] = 0;
						if (sah(xra, yra) == 0) {
							okkk = 1;
							deselect(lin[xx], col[yy]);
							stergere(lin[xx], col[yy]);
							completareCasute(coordX, coordY);
						}
						else
						{
							casuta[xx][yy] = casuta[coordX][coordY];
							casuta[coordX][coordY] = v2;
						}
					}
					else
					{
						sahh = 1;
						v = casuta[coordX][coordY];
						casuta[coordX][coordY] = 9;
						if (sah(xra, yra) == 0) {
							sahh = 0;
							okkk = 1;
							casuta[coordX][coordY] = casuta[xx][yy];
							casuta[xx][yy] = 0;
							deselect(lin[xx], col[yy]);
							stergere(lin[xx], col[yy]);
							completareCasute(coordX, coordY);
						}
						else
						{
							casuta[coordX][coordY] = v;
						}
					}
				}
				else
				{
					if (sah(xrn, yrn) == 0) {
						v2 = casuta[coordX][coordY];
						casuta[coordX][coordY] = casuta[xx][yy];
						casuta[xx][yy] = 0;
						if (sah(xrn, yrn) == 0) {
							okkk = 1;
							deselect(lin[xx], col[yy]);
							stergere(lin[xx], col[yy]);
							completareCasute(coordX, coordY);
						}
						else
						{
							casuta[xx][yy] = casuta[coordX][coordY];
							casuta[coordX][coordY] = v2;
						}
					}
					else
					{
						sahh = 1;
						v = casuta[coordX][coordY];
						casuta[coordX][coordY] = 9;
						if (sah(xrn, yrn) == 0) {
							sahh = 0;
							okkk = 1;
							casuta[coordX][coordY] = casuta[xx][yy];
							casuta[xx][yy] = 0;
							deselect(lin[xx], col[yy]);
							stergere(lin[xx], col[yy]);
							completareCasute(coordX, coordY);
						}
						else
						{
							casuta[coordX][coordY] = v;
						}
					}
				}

			}
			else
			{
				ok10 = 1;
				if (sw == 1) {
					if (xx == 8 && yy == 5) {
						if (albe[1] == 1 && albe[2] == 1 && coordX == 8 && coordY == 1) {
							if (verifRocada(xx, yy, coordX, coordY) == 1) {
								albe[1] = 0;
								albe[2] = 0;
								deselect(lin[xx], col[yy]);
								rocada(xx, yy, coordX, coordY);
								okkk = 1;
							}
						}
						else
						{
							if (albe[2] == 1 && albe[3] == 1 && coordX == 8 && coordY == 8) {
								if (verifRocada(xx, yy, coordX, coordY) == 1) {
									albe[2] = 0;
									albe[3] = 0;
									deselect(lin[xx], col[yy]);
									rocada(xx, yy, coordX, coordY);
									okkk = 1;
								}
							}
						}
					}
				}
				else
				{
					if (xx == 8 && yy == 4) {
						if (negre[1] == 1 && negre[2] == 1 && coordX == 8 && coordY == 1) {
							if (verifRocada(xx, yy, coordX, coordY) == 1) {
								negre[1] = 0;
								negre[2] = 0;
								deselect(lin[xx], col[yy]);
								rocada(xx, yy, coordX, coordY);
								okkk = 1;
							}
						}
						else
						{
							if (negre[2] == 1 && negre[3] == 1 && coordX == 8 && coordY == 8) {
								if (verifRocada(xx, yy, coordX, coordY) == 1) {
									negre[2] = 0;
									negre[3] = 0;
									deselect(lin[xx], col[yy]);
									rocada(xx, yy, coordX, coordY);
									okkk = 1;

								}
							}
						}
					}
				}
			}
		}
		index = 1;
		for (jndex = 1; jndex <= 8; jndex++) {
			if (sw == 1) {
				if (casuta[index][jndex] == 1) {
					schimbarePion(index, jndex);
				}
			}
			else
			{
				if (casuta[index][jndex] == -1) {
					schimbarePion(index, jndex);
				}
			}
		}

		if (sw == 1) {
			if (sah(xrn, yrn) == 1) {
				if (sahMat(xrn, yrn) == 1) {
					ok = 0;
					sm = 1;
				}
			}
		}
		else
		{
			if (sah(xra, yra) == 1) {
				if (sahMat(xra, yra) == 1) {
					ok = 0;
					sm = 1;
				}
			}
		}
		if (sw == 1) {
			if (pat(xrn, yrn) == 0) {
				ok = 0;
			}
		}
		else
		{
			if (pat(xra, yra) == 0) {
				ok = 0;
			}
		}
	}

	afisare();
	if (sm == 1) {
		cout << "\ \ \ \ SAH MAT !!!" << endl << endl;
		cout << "\ \ \ \ Castigator ";
		if (sw == 1) {
			cout << p1 << " !!!";
		}
		else
		{
			cout << p2 << " !!!";
		}
	}
	else
	{
		cout << "\ \ \ \ PAT !!! Remiza.";
	}
}
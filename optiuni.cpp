
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "chessHeader.h"
using namespace std;

char tabla[100][100], auxTabla[100][100], sirCaractere[10];
int col[10] = { 1,7,15,23,31,39,47,55,63,69 }, lin[10] = { 1,4,9,14,19,24,29,34,39,43 }, casuta[10][10], aux2[10][10], coordX, coordY, xra, yra, xrn, yrn;


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


int sahMat(int x, int y);


int pat(int x, int y);

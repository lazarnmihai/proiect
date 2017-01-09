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


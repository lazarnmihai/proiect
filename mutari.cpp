
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "chessHeader.h"
using namespace std;

char tabla[100][100], auxTabla[100][100], sirCaractere[10];
int col[10] = { 1,7,15,23,31,39,47,55,63,69 }, lin[10] = { 1,4,9,14,19,24,29,34,39,43 }, casuta[10][10], aux2[10][10], coordX, coordY, xra, yra, xrn, yrn;


int opuse(int xx1, int yy1, int xx2, int yy2);


int mutarePionInvers(int x1, int y1, int x2, int y2);


int mutarePion(int x1, int y1, int x2, int y2);


int mutareTura(int x1, int y1, int x2, int y2);


int mutareCal(int x1, int y1, int x2, int y2);


int mutareNebun(int x1, int y1, int x2, int y2);


int mutareRegina(int x1, int y1, int x2, int y2);


int mutareRege(int x1, int y1, int x2, int y2);


void schimbarepion(int x1, int y1);


int verifRocada(int x1, int y1, int x2, int y2);


void rocada(int x1, int y1, int x2, int y2);


int mutare(int cooX1, int cooY1, int cooX2, int cooY2);


int sahMat(int x, int y);


int pat(int x, int y);
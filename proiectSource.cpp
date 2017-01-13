
#include <iostream>
#include "chessHeader.h"

using namespace std;



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
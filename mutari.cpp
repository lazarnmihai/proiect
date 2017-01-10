
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "chessHeader.h"
using namespace std;

char tabla[100][100], auxTabla[100][100], sirCaractere[10];
int col[10] = { 1,7,15,23,31,39,47,55,63,69 }, lin[10] = { 1,4,9,14,19,24,29,34,39,43 }, casuta[10][10], aux2[10][10], coordX, coordY, xra, yra, xrn, yrn;


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

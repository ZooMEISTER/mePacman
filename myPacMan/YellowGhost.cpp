#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>

#include"Ghost.h"
#include"MAP.h"

using namespace std;

struct point {
	int x;
	int y;
};

bool IsCrossRoad(int curX, int curY) {
	int emptyWay = 0;
	if (map3[curX + 1][curY] != WALL && map3[curX + 1][curY] != TELEPORT) {
		emptyWay++;
	}
	if (map3[curX][curY + 1] != WALL && map3[curX][curY + 1] != TELEPORT) {
		emptyWay++;
	}
	if (map3[curX - 1][curY] != WALL && map3[curX - 1][curY] != TELEPORT) {
		emptyWay++;
	}
	if (map3[curX][curY - 1] != WALL && map3[curX][curY - 1] != TELEPORT) {
		emptyWay++;
	}

	if (emptyWay > 2) return true;
	return false;
}

void YellowGhost::YellowGhostMove() {
	if (dir == 0) y++;
	else if (dir == 1) x++;
	else if (dir == 2) y--;
	else if (dir == 3) x--;

	//if (IsCrossRoad(x, y)) {
	//	cout << "isisisisisisisisisisisissiiss";
	//}
	//Sleep(500);

	switch (dir) {
	case 0: {
		if (map3[x + 1][y] == WALL && map3[x - 1][y] == WALL && map3[x][y + 1] == WALL) {
			dir = 2;
			return;
		}

		if (map3[x][y + 1] == WALL && !IsCrossRoad(x, y)) {
			if (map3[x - 1][y] != WALL) dir = 3;
			else dir = 1;
		}
		break;
	}
	case 1: {
		if (map3[x + 1][y] == WALL && !IsCrossRoad(x, y)) {
			if (map3[x][y - 1] != WALL) dir = 2;
			else dir = 0;
		}
		break;
	}
	case 2: {
		if (map3[x + 1][y] == WALL && map3[x - 1][y] == WALL && map3[x][y - 1] == WALL) {
			dir = 0;
			return;
		}

		if (map3[x][y - 1] == WALL && !IsCrossRoad(x, y)) {
			if (map3[x - 1][y] != WALL) dir = 3;
			else dir = 1;
		}
		break;
	}
	case 3: {
		if (map3[x - 1][y] == WALL && !IsCrossRoad(x, y)) {
			if (map3[x][y - 1] != WALL) dir = 2;
			else dir = 0;
		}
		break;
	}
	}

	//Ëæ»ú×ªÏò
	if (IsCrossRoad(x, y) && !(x == 10 && y == 7) && !(x == 10 && y == 13)) {
		srand((unsigned)time(NULL));
		switch (dir) {
		case 0: {
			if (map3[x][y + 1] == WALL) {
				int t = rand() % 2;
				if (t == 0) dir = 3;
				else dir = 1;
			}
			else {
				if (map3[x - 1][y] == WALL) {
					int t = rand() % 2;
					if (t == 0) dir = 0;
					else dir = 1;
				}
				else {
					int t = rand() % 2;
					if (t == 0) dir = 0;
					else dir = 3;
				}
			}
			break;
		}
		case 1: {
			if (map3[x + 1][y] == WALL) {
				int t = rand() % 2;
				if (t == 0) dir = 0;
				else dir = 2;
			}
			else {
				if (map3[x][y - 1] == WALL) {
					int t = rand() % 2;
					if (t == 0) dir = 0;
					else dir = 1;
				}
				else {
					int t = rand() % 2;
					if (t == 0) dir = 1;
					else dir = 2;
				}
			}
			break;
		}
		case 2: {
			if (map3[x][y - 1] == WALL) {
				int t = rand() % 2;
				if (t == 0) dir = 3;
				else dir = 1;
			}
			else {
				if (map3[x - 1][y] == WALL) {
					int t = rand() % 2;
					if (t == 0) dir = 2;
					else dir = 1;
				}
				else {
					int t = rand() % 2;
					if (t == 0) dir = 2;
					else dir = 3;
				}
			}
			break;
		}
		case 3: {
			if (map3[x - 1][y] == WALL) {
				int t = rand() % 2;
				if (t == 0) dir = 0;
				else dir = 2;
			}
			else {
				if (map3[x][y - 1] == WALL) {
					int t = rand() % 2;
					if (t == 0) dir = 0;
					else dir = 3;
				}
				else {
					int t = rand() % 2;
					if (t == 0) dir = 2;
					else dir = 3;
				}
			}
			break;
		}
		}
	}
}
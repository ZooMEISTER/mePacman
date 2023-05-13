#include<iostream>
#include<conio.h>

#include"PacMan.h"
#include"MAP.h"
#include"Ghost.h"

using namespace std;

int pacDir = 0;
int eatFood = 0;

void PacMan::PacManMove() { //pacman的移动
	//map[x][y] = PACMAN;
	int tmpx = x, tmpy = y, tmpdir = pacDir;
	if (_kbhit()) {
		int ch = 0;
		ch = _getch();
		switch (ch) {
		case 100: {
			if (map[x][y + 1] != WALL) pacDir = 0;
			break;
		}
		case 115: {
			if (map[x + 1][y] != WALL) pacDir = 1;
			break;
		}
		case 97: {
			if (map[x][y - 1] != WALL) pacDir = 2;
			break;
		}
		case 119: {
			if (map[x - 1][y] != WALL) pacDir = 3;
			break;
		}
		}
	}

	map[tmpx][tmpy] = EMPTY;

	switch (pacDir) {
	case 0: {
		if (map[x][y + 1] != WALL) {
			y++;
		}
		else	if (map[x][y - 1] != WALL) {
			y--;
			pacDir= 2;
		}
		else {
			pacDir= tmpdir;
		}
		break;
	}
	case 1: {
		if (map[x + 1][y] != WALL && (x != 8 || y != 10)) {
			x++;
		}
		else	if (map[x - 1][y] != WALL) {
			x--;
			pacDir= 3;
		}
		else {
			pacDir= tmpdir;
		}
		break;
	}
	case 2: {
		if (map[x][y - 1] != WALL) {
			y--;
		}
		else	if (map[x][y + 1] != WALL) {
			y++;
			pacDir = 0;
		}
		else {
			pacDir = tmpdir;
		}
		break;
	}
	case 3: {
		if (map[x - 1][y] != WALL) {
			x--;
		}
		else	if (map[x + 1][y] != WALL && (x != 8 || y != 10)) {
			x++;
			pacDir= 1;
		}
		else {
			pacDir = tmpdir;
		}
		break;
	}
	}
	
	pacManx = x, pacMany = y;
	//传送门
	if (pacManx == 10 && pacMany == 0) {
		pacManx = 10; pacMany = 19;
		x = 10; y = 19;
	}
	else if (pacManx == 10 && pacMany == 20) {
		pacManx = 10; pacMany = 1;
		x = 10; y = 1;
	}

	pacManx = x, pacMany = y;

	//bool isFood = false;
	if (map[x][y] == FOOD) {
		eatFood++;
	}
	else if (map[x][y] == PILL) {
		ghostStatus = 0;
		mode0 = 10000;     //大力丸时间
	}
	
	map[pacManx][pacMany] = PACMAN;
}
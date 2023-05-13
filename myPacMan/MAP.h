#pragma once

#ifndef RTPP_H
#define RTPP_H

#include<iostream>
using namespace std;

#define WALL -1
#define FOOD 2
#define VISITED 3
#define WAY 4
#define PILL 5

#define GHOST1 21
#define GHOST2 22
#define GHOST3 23
#define PACMAN 1
#define TELEPORT 10
#define EMPTY 11

extern int map[21][21];
extern int oldMap[21][21];
extern int map1[21][21];
extern int map2[21][21];
extern int map3[21][21];
extern int pacManx, pacMany;  //全局 用于指示pacman的位置
extern int pacDir;
extern int eatFood;

extern int mode0;
extern int ghostStatus;

void DrawGame();
void DrawGameNoFlash();
void HideCursor(bool Visible);
void gotoxy(int x, int y);
void DrawGame2();

#endif // RTPP_H
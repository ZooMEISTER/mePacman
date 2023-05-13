#pragma once
#include<iostream>

using namespace std;
//逃跑逻辑：往出生点跑

class RedGhost {  //blinky
	public:
		int x, y;            //幽灵位置
		int speed;        //幽灵速度
		int status;        //幽灵状态 0为在逃跑  1为在追逐 
		int dir;             //移动方向     0右   1下   2左   3上
		void RedGhostMove();   //幽灵移动   0右   1下   2左   3上
		RedGhost(int m, int n, int sp, int st, int d) {
			x = m; y = n; speed = sp; status = st; dir = d;
		}
};

class PinkGhost {  //pinky
public:
	int x, y;            //幽灵位置
	int speed;        //幽灵速度
	int status;        //幽灵状态 0为在逃跑  1为在追逐 
	int dir;             //移动方向     0右   1下   2左   3上
	void PinkGhostMove();   //幽灵移动   0右   1下   2左   3上
	PinkGhost(int m, int n, int sp, int st, int d) {
		x = m; y = n; speed = sp; status = st; dir = d;
	}
};

class YellowGhost {  //clyde
public:
	int x, y;            //幽灵位置
	int speed;        //幽灵速度
	int status;        //幽灵状态 0为在逃跑  1为在追逐 
	int dir;             //移动方向     0右   1下   2左   3上
	void YellowGhostMove();   //幽灵移动   0右   1下   2左   3上
	YellowGhost(int m, int n, int sp, int st, int d) {
		x = m; y = n; speed = sp; status = st; dir = d;
	}
};
#pragma once
#include<iostream>

using namespace std;
//�����߼�������������

class RedGhost {  //blinky
	public:
		int x, y;            //����λ��
		int speed;        //�����ٶ�
		int status;        //����״̬ 0Ϊ������  1Ϊ��׷�� 
		int dir;             //�ƶ�����     0��   1��   2��   3��
		void RedGhostMove();   //�����ƶ�   0��   1��   2��   3��
		RedGhost(int m, int n, int sp, int st, int d) {
			x = m; y = n; speed = sp; status = st; dir = d;
		}
};

class PinkGhost {  //pinky
public:
	int x, y;            //����λ��
	int speed;        //�����ٶ�
	int status;        //����״̬ 0Ϊ������  1Ϊ��׷�� 
	int dir;             //�ƶ�����     0��   1��   2��   3��
	void PinkGhostMove();   //�����ƶ�   0��   1��   2��   3��
	PinkGhost(int m, int n, int sp, int st, int d) {
		x = m; y = n; speed = sp; status = st; dir = d;
	}
};

class YellowGhost {  //clyde
public:
	int x, y;            //����λ��
	int speed;        //�����ٶ�
	int status;        //����״̬ 0Ϊ������  1Ϊ��׷�� 
	int dir;             //�ƶ�����     0��   1��   2��   3��
	void YellowGhostMove();   //�����ƶ�   0��   1��   2��   3��
	YellowGhost(int m, int n, int sp, int st, int d) {
		x = m; y = n; speed = sp; status = st; dir = d;
	}
};
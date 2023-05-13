#include<iostream>
#include<math.h>

#include"Ghost.h"
#include"MAP.h"

using namespace std;
//原来的深度优先算法（有bug）
//struct point {
//	int x;
//	int y;
//};
//
//int targetX_Pink, targetY_Pink; //终点坐标
//point curPoint_Pink;   //寻路时的当前节点
//char backDir_Pink;
//
////返回一个方向值 用于表示下一次的寻找方向
//int GetNextBlockDir(int x, int y) {
//	//DrawGame();
//	if (x == targetX_Pink && y == targetY_Pink) {
//		return 4;
//	}
//
//	double t0, t1, t2, t3;
//	//if (map2[x - 1][y] == EMPTY) t0 = 19 + 1 - x + 1 + 19 + 1 - y;
//	//else t0 = 1000;
//	//if (map2[x][y + 1] == EMPTY) t1 = 19 + 1 - x + 19 + 1 - y - 1;
//	//else t1 = 1000;
//	//if (map2[x + 1][y] == EMPTY) t2 = 19 + 1 - x - 1 + 19 + 1 - y;
//	//else t2 = 1000;
//	//if (map2[x][y - 1] == EMPTY) t3 = 19 + 1 - x + 19 + 1 - y + 1;
//	//else t3 = 1000;
//
//	/*if (map2[x - 1][y] == EMPTY) t0 = abs(x - 1 -targetX_Pink) + abs(y - targetY_Pink);
//	else t0 = 1000;
//	if (map2[x][y + 1] == EMPTY) t1 = abs(x - targetX_Pink) + abs(y + 1 - targetY_Pink);
//	else t1 = 1000;
//	if (map2[x + 1][y] == EMPTY) t2 = abs(x + 1 - targetX_Pink) + abs(y - targetY_Pink);
//	else t2 = 1000;
//	if (map2[x][y - 1] == EMPTY) t3 = abs(x - targetX_Pink) + abs(y - 1 - targetY_Pink);
//	else t3 = 1000;*/
//
//	//直线距离作为权值
//	if (map2[x - 1][y] == EMPTY || map2[x - 1][y] == PACMAN) t0 = sqrt((x - 1 - targetX_Pink) * (x - 1 - targetX_Pink) + (y - targetY_Pink) * (y - targetY_Pink));
//	else t0 = 1000;
//	if (map2[x][y + 1] == EMPTY || map2[x][y + 1] == PACMAN) t1 = sqrt((x - targetX_Pink) * (x - targetX_Pink) + (y + 1 - targetY_Pink) * (y + 1 - targetY_Pink));
//	else t1 = 1000;
//	if (map2[x + 1][y] == EMPTY || map2[x + 1][y] == PACMAN) t2 = sqrt((x + 1 - targetX_Pink) * (x + 1 - targetX_Pink) + (y - targetY_Pink) * (y - targetY_Pink));
//	else t2 = 1000;
//	if (map2[x][y - 1] == EMPTY || map2[x][y - 1] == PACMAN) t3 = sqrt((x - targetX_Pink) * (x - targetX_Pink) + (y - 1 - targetY_Pink) * (y - 1 - targetY_Pink));
//	else t3 = 1000;
//
//	if (t0 != 1000 || t1 != 1000 || t2 != 1000 || t3 != 1000) {
//		if (t0 <= t2) {
//			if (t1 <= t3) {
//				if (t0 <= t1) {
//					map2[x][y] = WAY;
//					return 0;
//				}
//				else {
//					map2[x][y] = WAY;
//					return 1;
//				}
//			}
//			else {
//				if (t0 <= t3) {
//					map2[x][y] = WAY;
//					return 0;
//				}
//				else {
//					map2[x][y] = WAY;
//					return 3;
//				}
//			}
//		}
//		else {
//			if (t1 <= t3) {
//				if (t2 <= t1) {
//					map2[x][y] = WAY;
//					return 2;
//				}
//				else {
//					map2[x][y] = WAY;
//					return 1;
//				}
//			}
//			else {
//				if (t2 <= t3) {
//					map2[x][y] = WAY;
//					return 2;
//				}
//				else {
//					map2[x][y] = WAY;
//					return 3;
//				}
//			}
//		}
//	}
//	else {
//		return -1;
//	}
//}
//
////碰壁了 开始回溯寻找
//void FindWayBack(char bd, int& bt) {  //回溯方向和首次标记
//	//DrawGame2();
//	//cout << "4";
//	if (bt == 1) {
//		if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] == WAY && bd == 'u') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x--;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] == WAY && bd == 'r') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y++;
//		}
//		else if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] == WAY && bd == 'd') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x++;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] == WAY && bd == 'l') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y--;
//		}
//		bt--;
//	}
//	else {
//		if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x--;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y++;
//		}
//		else if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x++;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y--;
//		}
//	}
//
//	//DrawGame();
//}
//
////主要过程
//void FindPath(int s) {
//	bool alreadyFound = false;
//	int tx, ty;
//
//	if (s == 1) {
//		/*if (pacDir == 0) {
//			int i;
//			for (i = pacMany; map2[pacManx][i] != WALL; ++i);
//			tx = pacManx; ty = i - 1;
//		}
//		else if (pacDir == 1) {
//			int i;
//			for (i = pacManx; map2[i][pacMany] != WALL; ++i);
//			tx = i - 1; ty = pacMany;
//		}
//		else if (pacDir == 2) {
//			int i;
//			for (i = pacMany; map2[pacManx][i] != WALL; --i);
//			tx = pacManx; ty = i + 1;
//		}
//		else if (pacDir == 3) {
//			int i;
//			for (i = pacManx; map2[i][pacMany] != WALL; --i);
//			tx = i + 1; ty = pacMany;
//		}*/
//		if (pacDir == 0) {
//			int i;
//			for (i = pacMany; map2[pacManx][i] != WALL && map2[pacManx][i] != TELEPORT; ++i);
//			tx = pacManx; ty = i - 1;
//		}
//		else if (pacDir == 1) {
//			int i;
//			for (i = pacManx; map2[i][pacMany] != WALL && map2[i][pacMany] != TELEPORT; ++i);
//			tx = i - 1; ty = pacMany;
//		}
//		else if (pacDir == 2) {
//			int i;
//			for (i = pacMany; map2[pacManx][i] != WALL && map2[pacManx][i] != TELEPORT; --i);
//			tx = pacManx; ty = i + 1;
//		}
//		else if (pacDir == 3) {
//			int i;
//			for (i = pacManx; map2[i][pacMany] != WALL && map2[i][pacMany] != TELEPORT; --i);
//			tx = i + 1; ty = pacMany;
//		}
//
//		//-------------------------------------------
//
//		targetX_Pink = tx;
//		targetY_Pink = ty;
//
//		//-------------------------------------------
//	}
//	else if (s == 0) {
//		targetX_Pink = 10;
//		targetY_Pink = 10;
//	}
//
//	while (!alreadyFound) {
//		//cout << "1";
//		while (GetNextBlockDir(curPoint_Pink.x, curPoint_Pink.y) != -1) {
//			if (GetNextBlockDir(curPoint_Pink.x, curPoint_Pink.y) == 0) {
//				curPoint_Pink.x--;
//				backDir_Pink = 'd';
//			}
//			else if (GetNextBlockDir(curPoint_Pink.x, curPoint_Pink.y) == 1) {
//				curPoint_Pink.y++;
//				backDir_Pink = 'l';
//			}
//			else if (GetNextBlockDir(curPoint_Pink.x, curPoint_Pink.y) == 2) {
//				curPoint_Pink.x++;
//				backDir_Pink = 'u';
//			}
//			else if (GetNextBlockDir(curPoint_Pink.x, curPoint_Pink.y) == 3) {
//				curPoint_Pink.y--;
//				backDir_Pink = 'r';
//			}
//			else if (GetNextBlockDir(curPoint_Pink.x, curPoint_Pink.y) == 4) {
//				return;
//			}
//			//cout << "2";
//		}
//		//DrawGame();
//		//cout << "4";
//
//		int backT = 1;
//		while (GetNextBlockDir(curPoint_Pink.x, curPoint_Pink.y) == -1) {
//			if (curPoint_Pink.x == targetX_Pink && curPoint_Pink.y == targetY_Pink) {
//				alreadyFound = true;
//				return;
//				//cout << "3";
//			}
//			FindWayBack(backDir_Pink, backT);   //此处需指定回退方向
//			//DrawGame();
//			//cout << "3";
//			
//			//DrawGame();
//		}
//		//DrawGame();
//	}
//}
//
//void PinkGhost::PinkGhostMove() {
//	for (int p = 0; p < 21; ++p)
//		for (int q = 0; q < 21; ++q) {
//			if (map2[p][q] == WAY || map2[p][q] == VISITED || map2[p][q] == GHOST2) {
//				map2[p][q] = EMPTY;
//			}
//		}
//
//	//map2[this->y][this->x] = GHOST2;
//
//	curPoint_Pink.x = this->x;
//	curPoint_Pink.y = this->y;
//	//map2[this->x][this->y] = WAY;
//
//	status = ghostStatus;
//	FindPath(status);
//
//	if (map2[this->x][this->y + 1] == WAY) {
//		dir = 0;
//	}
//	else if (map2[this->x + 1][this->y] == WAY) {
//		dir = 1;
//	}
//	else if (map2[this->x][this->y - 1] == WAY) {
//		dir = 2;
//	}
//	else if (map2[this->x - 1][this->y] == WAY) {
//		dir = 3;
//	}
//
//	switch (dir) {
//	case 0: {   //右
//		this->y += 1;
//		break;
//	}
//	case 1: {   //下
//		this->x += 1;
//		break;
//	}
//	case 2: {   //左
//		this->y -= 1;
//		break;
//	}
//	case 3: {   //上
//		this->x -= 1;
//		break;
//	}
//	}
//}

struct point {
	int x = 1;
	int y = 1;
	int value = 0;
	bool free = true;
	char comeDir = 'm';      //记录来时的方向    r为从右边来     d为从下面来      l为从左边来      u为从右边来     m为起始点
};

int targetX_Pink, targetY_Pink; //终点坐标
point curPoint_Pink;   //寻路时的当前节点
point searchedPoint_P[400];       //搜索过的节点
point emptySearchedPoint_P[400];
int searchPointCount_P = 0;       //搜索过的节点计数
char backDir_Pink;


//碰壁了 开始回溯寻找
//void FindWayBack_Pink(char bd, int& bt) {
//	if (bt == 1) {
//		if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] == WAY && bd == 'u') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x--;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] == WAY && bd == 'r') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y++;
//		}
//		else if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] == WAY && bd == 'd') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x++;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] == WAY && bd == 'l') {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y--;
//		}
//		bt--;
//	}
//	else {
//		if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x--;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y++;
//		}
//		else if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.x++;
//		}
//		else if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] == WAY) {
//			map2[curPoint_Pink.x][curPoint_Pink.y] = VISITED;
//			curPoint_Pink.y--;
//		}
//	}
//}

//指示该点是否搜索过
bool IsPointSearched_P(point p0) {
	for (int i = 0; i < searchPointCount_P; ++i) {
		if (p0.x == searchedPoint_P[i].x && p0.y == searchedPoint_P[i].y) return true;
	}
	return false;
}

point GetPoint_P(int x, int y) {
	for (int i = 0; i < searchPointCount_P; ++i) {
		if (x == searchedPoint_P[i].x && y == searchedPoint_P[i].y) return searchedPoint_P[i];
	}
}

//返回已搜索点中权值最小的点的下标
int curMinValPointNum_P = 0;
int GetMinValuePoint_P() {
	for (int i = 0; i < searchPointCount_P; ++i) {
		if (searchedPoint_P[i].free) {
			curMinValPointNum_P = i;
			break;
		}
	}

	for (int i = 0; i < searchPointCount_P; ++i) {
		if (searchedPoint_P[i].value <= searchedPoint_P[curMinValPointNum_P].value && searchedPoint_P[i].free == true) curMinValPointNum_P = i;
	}
	return curMinValPointNum_P;
}

//用于指示该点周围是否有空    -1没空    0右空     1下空     2左空    3上空
int IsPointFree_P(point p0) {
	if ((map2[p0.x - 1][p0.y] == WALL || map2[p0.x - 1][p0.y] == TELEPORT || map2[p0.x - 1][p0.y] == VISITED) && (map2[p0.x][p0.y - 1] == WALL || map2[p0.x][p0.y - 1] == TELEPORT || map2[p0.x][p0.y - 1] == VISITED) && (map2[p0.x + 1][p0.y] == WALL || map2[p0.x + 1][p0.y] == TELEPORT || map2[p0.x + 1][p0.y] == VISITED) && (map2[p0.x][p0.y + 1] == WALL || map2[p0.x][p0.y + 1] == TELEPORT || map2[p0.x][p0.y + 1] == VISITED)) return -1;
	else if (map2[p0.x][p0.y + 1] != WALL && map2[p0.x][p0.y + 1] != TELEPORT && map2[p0.x][p0.y + 1] != VISITED) return 0;
	else if (map2[p0.x + 1][p0.y] != WALL && map2[p0.x + 1][p0.y] != TELEPORT && map2[p0.x + 1][p0.y] != VISITED) return 1;
	else if (map2[p0.x][p0.y - 1] != WALL && map2[p0.x][p0.y - 1] != TELEPORT && map2[p0.x][p0.y - 1] != VISITED) return 2;
	else if (map2[p0.x - 1][p0.y] != WALL && map2[p0.x - 1][p0.y] != TELEPORT && map2[p0.x - 1][p0.y] != VISITED) return 3;
}

int getMin2_P(int a, int b) {
	return a < b ? a : b;
}

int getMin4_P(int t0, int t1, int t2, int t3) {
	if (t0 == getMin2_P(getMin2_P(t0, t1), getMin2_P(t2, t3))) {
		return 0;
	}
	else if (t1 == getMin2_P(getMin2_P(t0, t1), getMin2_P(t2, t3))) {
		return 1;
	}
	else if (t2 == getMin2_P(getMin2_P(t0, t1), getMin2_P(t2, t3))) {
		return 2;
	}
	else if (t3 == getMin2_P(getMin2_P(t0, t1), getMin2_P(t2, t3))) {
		return 3;
	}
}

//对输入的点进行下一个方向判断  0向右   1向下    2向左   3向上
int GetNextBlockDir_Pink(point p0) {
	int t0, t1, t2, t3;
	if (map2[p0.x][p0.y + 1] != WALL && map2[p0.x][p0.y + 1] != TELEPORT && map2[p0.x][p0.y + 1] != VISITED) t0 = p0.value + 1 + abs(p0.x - targetX_Pink) + abs(p0.y + 1 - targetY_Pink);
	else t0 = 1000;
	if (map2[p0.x + 1][p0.y] != WALL && map2[p0.x + 1][p0.y] != TELEPORT && map2[p0.x + 1][p0.y] != VISITED) t1 = p0.value + 1 + abs(p0.x + 1 - targetX_Pink) + abs(p0.y - targetY_Pink);
	else t1 = 1000;
	if (map2[p0.x][p0.y - 1] != WALL && map2[p0.x][p0.y - 1] != TELEPORT && map2[p0.x][p0.y - 1] != VISITED) t2 = p0.value + 1 + abs(p0.x - targetX_Pink) + abs(p0.y - 1 - targetY_Pink);
	else t2 = 1000;
	if (map2[p0.x - 1][p0.y] != WALL && map2[p0.x - 1][p0.y] != TELEPORT && map2[p0.x - 1][p0.y] != VISITED) t3 = p0.value + 1 + abs(p0.x - 1 - targetX_Pink) + abs(p0.y - targetY_Pink);
	else t3 = 1000;

	return getMin4_P(t0, t1, t2, t3);
}

//主要过程
void FindPath_Pink(int s, int curX, int curY) {
	bool alreadyFound = false;

	if (s == 1) {
		int tx, ty;
		if (pacDir == 0) {
		int i;
		for (i = pacMany; map2[pacManx][i] != WALL && map2[pacManx][i] != TELEPORT && map2[pacManx][i] != GHOST1 && map2[pacManx][i] != GHOST2 && map2[pacManx][i] != GHOST3; ++i);
			tx = pacManx; ty = i - 1;
		}
		else if (pacDir == 1) {
			int i;
			for (i = pacManx; map2[i][pacMany] != WALL && map2[i][pacMany] != TELEPORT && map2[pacManx][i] != GHOST1 && map2[pacManx][i] != GHOST2 && map2[pacManx][i] != GHOST3; ++i);
			tx = i - 1; ty = pacMany;
		}
		else if (pacDir == 2) {
			int i;
			for (i = pacMany; map2[pacManx][i] != WALL && map2[pacManx][i] != TELEPORT && map2[pacManx][i] != GHOST1 && map2[pacManx][i] != GHOST2 && map2[pacManx][i] != GHOST3; --i);
			tx = pacManx; ty = i + 1;
		}
		else if (pacDir == 3) {
			int i;
			for (i = pacManx; map2[i][pacMany] != WALL && map2[i][pacMany] != TELEPORT && map2[pacManx][i] != GHOST1 && map2[pacManx][i] != GHOST2 && map2[pacManx][i] != GHOST3; --i);
			tx = i + 1; ty = pacMany;
		}
			
		//-------------------------------------------
			
		targetX_Pink = tx;
		targetY_Pink = ty;
		
		if (tx == curX && ty == curY) {
			//cout << "insubuhncapunafipweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
			return;
		}
		//cout <<  << ;

		//-------------------------------------------
	}
	else if (s == 0) {
		targetX_Pink = 10;
		targetY_Pink = 11;
	}

	while (!alreadyFound) {
		//cout << "1";

		curPoint_Pink = searchedPoint_P[GetMinValuePoint_P()];
		while (IsPointFree_P(curPoint_Pink) == -1) {                    //使curPoint就是权值最小的点
			searchedPoint_P[GetMinValuePoint_P()].free = false;
			curPoint_Pink = searchedPoint_P[GetMinValuePoint_P()];
			//cout << "2";
		}

		switch (GetNextBlockDir_Pink(curPoint_Pink)) {
		case 0: {
			if (curPoint_Pink.x == targetX_Pink && curPoint_Pink.y + 1 == targetY_Pink) {
				alreadyFound = true;
			}
			if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y + 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y + 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'l';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x + 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x + 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'u';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y - 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y - 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'r';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x - 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x - 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'd';
				searchPointCount_P++;
			}

			break;
		}
		case 1: {
			if (curPoint_Pink.x + 1 == targetX_Pink && curPoint_Pink.y == targetY_Pink) {
				alreadyFound = true;
			}

			if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y + 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y + 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'l';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x + 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x + 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'u';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y - 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y - 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'r';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x - 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x - 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'd';
				searchPointCount_P++;
			}

			break;
		}
		case 2: {
			if (curPoint_Pink.x == targetX_Pink && curPoint_Pink.y - 1 == targetY_Pink) {
				alreadyFound = true;
			}

			if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y + 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y + 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'l';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x + 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x + 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'u';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y - 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y - 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'r';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x - 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x - 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'd';
				searchPointCount_P++;
			}

			break;
		}
		case 3: {
			if (curPoint_Pink.x - 1 == targetX_Pink && curPoint_Pink.y == targetY_Pink) {
				alreadyFound = true;
			}

			if (map2[curPoint_Pink.x][curPoint_Pink.y + 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y + 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y + 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y + 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'l';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x + 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x + 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x + 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x + 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'u';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x][curPoint_Pink.y - 1] != WALL && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != TELEPORT && map2[curPoint_Pink.x][curPoint_Pink.y - 1] != VISITED) {
				map2[curPoint_Pink.x][curPoint_Pink.y - 1] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y - 1;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'r';
				searchPointCount_P++;
			}
			if (map2[curPoint_Pink.x - 1][curPoint_Pink.y] != WALL && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != TELEPORT && map2[curPoint_Pink.x - 1][curPoint_Pink.y] != VISITED) {
				map2[curPoint_Pink.x - 1][curPoint_Pink.y] = VISITED;
				searchedPoint_P[searchPointCount_P].x = curPoint_Pink.x - 1;
				searchedPoint_P[searchPointCount_P].y = curPoint_Pink.y;
				searchedPoint_P[searchPointCount_P].value = curPoint_Pink.value + 1;
				searchedPoint_P[searchPointCount_P].comeDir = 'd';
				searchPointCount_P++;
			}

			break;
		}
		}
	}
}


void PinkGhost::PinkGhostMove() {
	searchPointCount_P = 0;
	curMinValPointNum_P = 0;
	for (int i = 0; i < 400; ++i) searchedPoint_P[i] = emptySearchedPoint_P[i];

	for (int p = 0; p < 21; ++p)
		for (int q = 0; q < 21; ++q) {
			if (map2[p][q] == WAY || map2[p][q] == VISITED || map2[p][q] == GHOST1) {
				map2[p][q] = EMPTY;
			}
		}

	curPoint_Pink.x = this->x;
	curPoint_Pink.y = this->y;

	searchedPoint_P[searchPointCount_P] = curPoint_Pink;
	searchPointCount_P++;
	map2[x][y] = VISITED;

	if (ghostStatus == 1) {
		targetX_Pink = pacManx;
		targetY_Pink = pacMany;
	}
	else if (ghostStatus == 0) {
		targetX_Pink = 10;
		targetY_Pink = 11;
	}

	if ((curPoint_Pink.x == targetX_Pink && curPoint_Pink.y == targetY_Pink)) {
		x = curPoint_Pink.x;
		y = curPoint_Pink.y;
		return;
	}
	else if ((curPoint_Pink.x == targetX_Pink && curPoint_Pink.y + 1 == targetY_Pink)) {
		dir = 0;
	}
	else if ((curPoint_Pink.x + 1 == targetX_Pink && curPoint_Pink.y == targetY_Pink)) {
		dir = 1;
	}
	else if ((curPoint_Pink.x == targetX_Pink && curPoint_Pink.y - 1 == targetY_Pink)) {
		dir = 2;
	}
	else if ((curPoint_Pink.x - 1 == targetX_Pink && curPoint_Pink.y == targetY_Pink)) {
		dir = 3;
	}
	else {

		status = ghostStatus;
		FindPath_Pink(status, x, y);
		//DrawGame();

		while (curPoint_Pink.comeDir != 'm') {
			map2[curPoint_Pink.x][curPoint_Pink.y] = WAY;
			//DrawGame();
			switch (curPoint_Pink.comeDir) {
			case 'r': {
				curPoint_Pink = GetPoint_P(curPoint_Pink.x, curPoint_Pink.y + 1);
				break;
			}
			case 'd': {
				curPoint_Pink = GetPoint_P(curPoint_Pink.x + 1, curPoint_Pink.y);
				break;
			}
			case 'l': {
				curPoint_Pink = GetPoint_P(curPoint_Pink.x, curPoint_Pink.y - 1);
				break;
			}
			case 'u': {
				curPoint_Pink = GetPoint_P(curPoint_Pink.x - 1, curPoint_Pink.y);
				break;
			}
			}
		}

		if (map2[this->x][this->y + 1] == WAY || map2[this->x][this->y + 1] == PACMAN) {
			dir = 0;
		}
		else if (map2[this->x + 1][this->y] == WAY || map2[this->x + 1][this->y] == PACMAN) {
			dir = 1;
		}
		else if (map2[this->x][this->y - 1] == WAY || map2[this->x][this->y - 1] == PACMAN) {
			dir = 2;
		}
		else if (map2[this->x - 1][this->y] == WAY || map2[this->x - 1][this->y] == PACMAN) {
			dir = 3;
		}
		//DrawGame();
	}


	switch (dir) {
	case 0: {   //右
		if(map[x][y + 1] != WALL && map[x][y + 1] != TELEPORT) this->y += 1;
		break;
	}
	case 1: {   //下
		if (map[x + 1][y] != WALL && map[x + 1][y] != TELEPORT) this->x += 1;
		break;
	}
	case 2: {   //左
		if (map[x][y - 1] != WALL && map[x][y - 1] != TELEPORT) this->y -= 1;
		break;
	}
	case 3: {   //上
		if (map[x - 1][y] != WALL && map[x - 1][y] != TELEPORT) this->x -= 1;
		break;
	}
	}
}
#include<iostream>
#include<math.h>

#include"Ghost.h"
#include"MAP.h"

using namespace std;

struct point {
	int x = 1;
	int y = 1;
	int value = 0;
	bool free = true;
	char comeDir = 'm';      //记录来时的方向    r为从右边来     d为从下面来      l为从左边来      u为从右边来     m为起始点
};

int targetX_Red, targetY_Red; //终点坐标
point curPoint_Red;   //寻路时的当前节点
point searchedPoint_R[400];       //搜索过的节点
point emptySearchedPoint_R[400];
int searchPointCount_R = 0;       //搜索过的节点计数
char backDir_Red;

//返回一个方向值 用于表示下一次的寻找方向
//int GetNextBlockDir_Red(int x, int y) {
//	//DrawGame();
//	if (x == targetX_Red && y == targetY_Red) {
//		return 4;
//	}
//
//	double t0, t1, t2, t3;
//	//if (map1[x - 1][y] == FOOD) t0 = 19 + 1 - x + 1 + 19 + 1 - y;
//	//else t0 = 1000;
//	//if (map1[x][y + 1] == FOOD) t1 = 19 + 1 - x + 19 + 1 - y - 1;
//	//else t1 = 1000;
//	//if (map1[x + 1][y] == FOOD) t2 = 19 + 1 - x - 1 + 19 + 1 - y;
//	//else t2 = 1000;
//	//if (map1[x][y - 1] == FOOD) t3 = 19 + 1 - x + 19 + 1 - y + 1;
//	//else t3 = 1000;
//
//	/*if (map1[x - 1][y] == FOOD) t0 = abs(x - 1 -targetX_Red) + abs(y - targetY_Red);
//	else t0 = 1000;
//	if (map1[x][y + 1] == FOOD) t1 = abs(x - targetX_Red) + abs(y + 1 - targetY_Red);
//	else t1 = 1000;
//	if (map1[x + 1][y] == FOOD) t2 = abs(x + 1 - targetX_Red) + abs(y - targetY_Red);
//	else t2 = 1000;
//	if (map1[x][y - 1] == FOOD) t3 = abs(x - targetX_Red) + abs(y - 1 - targetY_Red);
//	else t3 = 1000;*/
//
//	//直线距离作为权值
//	if (map1[x - 1][y] == FOOD || map1[x - 1][y] == PACMAN || map1[x - 1][y] == GHOST1) t0 = sqrt((x - 1 - targetX_Red) * (x - 1 - targetX_Red) +(y - targetY_Red) * (y - targetY_Red));
//	else t0 = 1000;
//	if (map1[x][y + 1] == FOOD || map1[x][y + 1] == PACMAN || map1[x][y + 1] == GHOST1) t1 = sqrt((x - targetX_Red) * (x - targetX_Red) + (y + 1 - targetY_Red) * (y + 1 - targetY_Red));
//	else t1 = 1000;
//	if (map1[x + 1][y] == FOOD || map1[x + 1][y] == PACMAN || map1[x + 1][y] == GHOST1) t2 = sqrt((x + 1 - targetX_Red) * (x + 1 - targetX_Red) +(y - targetY_Red) * (y - targetY_Red));
//	else t2 = 1000;
//	if (map1[x][y - 1] == FOOD || map1[x][y - 1] == PACMAN || map1[x][y - 1] == GHOST1) t3 = sqrt((x - targetX_Red) * (x - targetX_Red) + (y - 1 - targetY_Red) * (y - 1 - targetY_Red));
//	else t3 = 1000;
//
//	if (t0 != 1000 || t1 != 1000 || t2 != 1000 || t3 != 1000) {
//		if (t0 <= t2) {
//			if (t1 <= t3) {
//				if (t0 <= t1) {
//					map1[x][y] = WAY;
//					return 0;
//				}
//				else {
//					map1[x][y] = WAY;
//					return 1;
//				}
//			}
//			else {
//			if (t0 <= t3) {
//				map1[x][y] = WAY;
//				return 0;
//			}
//			else {
//				map1[x][y] = WAY;
//				return 3;
//			}
//			}
//		}
//		else {
//		if (t1 <= t3) {
//			if (t2 <= t1) {
//				map1[x][y] = WAY;
//				return 2;
//			}
//			else {
//				map1[x][y] = WAY;
//				return 1;
//			}
//		}
//		else {
//			if (t2 <= t3) {
//				map1[x][y] = WAY;
//				return 2;
//			}
//			else {
//				map1[x][y] = WAY;
//				return 3;
//			}
//		}
//		}
//	}
//	else {
//	return -1;
//	}
//}
//碰壁了 开始回溯寻找
//void FindWayBack_Red(char bd, int& bt) {
//	/*if (map1[curPoint_Red.x - 1][curPoint_Red.y] == WAY && bd == 'u') {
//		map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//		curPoint_Red.x--;
//	}
//	else if (map1[curPoint_Red.x][curPoint_Red.y + 1] == WAY && bd == 'r') {
//		map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//		curPoint_Red.y++;
//	}
//	else if (map1[curPoint_Red.x + 1][curPoint_Red.y] == WAY && bd == 'd') {
//		map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//		curPoint_Red.x++;
//	}
//	else if (map1[curPoint_Red.x][curPoint_Red.y - 1] == WAY && bd == 'l') {
//		map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//		curPoint_Red.y--;
//	}*/
//	if (bt == 1) {
//		if (map1[curPoint_Red.x - 1][curPoint_Red.y] == WAY && bd == 'u') {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.x--;
//		}
//		else if (map1[curPoint_Red.x][curPoint_Red.y + 1] == WAY && bd == 'r') {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.y++;
//		}
//		else if (map1[curPoint_Red.x + 1][curPoint_Red.y] == WAY && bd == 'd') {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.x++;
//		}
//		else if (map1[curPoint_Red.x][curPoint_Red.y - 1] == WAY && bd == 'l') {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.y--;
//		}
//		bt--;
//	}
//	else {
//		if (map1[curPoint_Red.x - 1][curPoint_Red.y] == WAY) {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.x--;
//		}
//		else if (map1[curPoint_Red.x][curPoint_Red.y + 1] == WAY) {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.y++;
//		}
//		else if (map1[curPoint_Red.x + 1][curPoint_Red.y] == WAY) {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.x++;
//		}
//		else if (map1[curPoint_Red.x][curPoint_Red.y - 1] == WAY) {
//			map1[curPoint_Red.x][curPoint_Red.y] = VISITED;
//			curPoint_Red.y--;
//		}
//	}
//}

//指示该点是否搜索过
bool IsPointSearched_R(point p0) {
	for (int i = 0; i < searchPointCount_R; ++i) {
		if (p0.x == searchedPoint_R[i].x && p0.y == searchedPoint_R[i].y) return true;
	}
	return false;
}

point GetPoint_R(int x, int y) {
	for (int i = 0; i < searchPointCount_R; ++i) {
		if (x == searchedPoint_R[i].x && y == searchedPoint_R[i].y) return searchedPoint_R[i];
	}
}

//返回已搜索点中权值最小的点的下标
int curMinValPointNum_R = 0;
int GetMinValuePoint_R() {
	for (int i = 0; i < searchPointCount_R; ++i) {
		if (searchedPoint_R[i].free) {
			curMinValPointNum_R = i;
			break;
		}
	}
	
	for (int i = 0; i < searchPointCount_R; ++i) {
		if (searchedPoint_R[i].value <= searchedPoint_R[curMinValPointNum_R].value && searchedPoint_R[i].free == true) curMinValPointNum_R = i;
	}
	return curMinValPointNum_R;
}

//用于指示该点周围是否有空    -1没空    0右空     1下空     2左空    3上空
int IsPointFree_R(point p0) {
	if ((map1[p0.x - 1][p0.y] == WALL || map1[p0.x - 1][p0.y] == TELEPORT || map1[p0.x - 1][p0.y] == VISITED) && (map1[p0.x][p0.y - 1] == WALL || map1[p0.x][p0.y - 1] == TELEPORT || map1[p0.x][p0.y - 1] == VISITED) && (map1[p0.x + 1][p0.y] == WALL || map1[p0.x + 1][p0.y] == TELEPORT || map1[p0.x + 1][p0.y] == VISITED) && (map1[p0.x][p0.y + 1] == WALL || map1[p0.x][p0.y + 1] == TELEPORT || map1[p0.x][p0.y + 1] == VISITED)) return -1;
	else if (map1[p0.x][p0.y + 1] != WALL && map1[p0.x][p0.y + 1] != TELEPORT && map1[p0.x][p0.y + 1] != VISITED) return 0;
	else if (map1[p0.x + 1][p0.y] != WALL && map1[p0.x + 1][p0.y] != TELEPORT && map1[p0.x + 1][p0.y] != VISITED) return 1;
	else if (map1[p0.x][p0.y - 1] != WALL && map1[p0.x][p0.y - 1] != TELEPORT && map1[p0.x][p0.y - 1] != VISITED) return 2;
	else if (map1[p0.x - 1][p0.y] != WALL && map1[p0.x - 1][p0.y] != TELEPORT && map1[p0.x - 1][p0.y] != VISITED) return 3;
}

int getMin2_R(int a, int b) {
	return a < b ? a : b;
}

int getMin4_R(int t0, int t1, int t2, int t3) {
	if (t0 == getMin2_R(getMin2_R(t0, t1), getMin2_R(t2, t3))) {
		return 0;
	}
	else if (t1 == getMin2_R(getMin2_R(t0, t1), getMin2_R(t2, t3))) {
		return 1;
	}
	else if (t2 == getMin2_R(getMin2_R(t0, t1), getMin2_R(t2, t3))) {
		return 2;
	}
	else if (t3 == getMin2_R(getMin2_R(t0, t1), getMin2_R(t2, t3))) {
		return 3;
	}
}

//对输入的点进行下一个方向判断  0向右   1向下    2向左   3向上
int GetNextBlockDir_Red(point p0) {
	int t0, t1, t2, t3;
	if (map1[p0.x][p0.y + 1] != WALL && map1[p0.x][p0.y + 1] != TELEPORT && map1[p0.x][p0.y + 1] != VISITED) t0 = p0.value + 1 + abs(p0.x - targetX_Red) + abs(p0.y + 1 - targetY_Red);
	else t0 = 1000;
	if (map1[p0.x + 1][p0.y] != WALL && map1[p0.x + 1][p0.y] != TELEPORT && map1[p0.x + 1][p0.y] != VISITED) t1 = p0.value + 1 + abs(p0.x + 1 - targetX_Red) + abs(p0.y - targetY_Red);
	else t1 = 1000;
	if (map1[p0.x][p0.y - 1] != WALL && map1[p0.x][p0.y - 1] != TELEPORT && map1[p0.x][p0.y - 1] != VISITED) t2 = p0.value + 1 + abs(p0.x - targetX_Red) + abs(p0.y - 1 - targetY_Red);
	else t2 = 1000;
	if (map1[p0.x - 1][p0.y] != WALL && map1[p0.x - 1][p0.y] != TELEPORT && map1[p0.x - 1][p0.y] != VISITED) t3 = p0.value + 1 + abs(p0.x - 1 - targetX_Red) + abs(p0.y - targetY_Red);
	else t3 = 1000;

	return getMin4_R(t0, t1, t2, t3);
}

//主要过程
void FindPath_Red(int s) {
	bool alreadyFound = false;
	
	if (s == 1) {
		targetX_Red = pacManx ;
		targetY_Red = pacMany;
	}
	else if (s == 0) {
		targetX_Red = 10;
		targetY_Red = 9;
	}


	//while (!alreadyFound) {
	//	while (GetNextBlockDir_Red(curPoint_Red.x, curPoint_Red.y) != -1) {
	//		if (GetNextBlockDir_Red(curPoint_Red.x, curPoint_Red.y) == 0) {
	//			curPoint_Red.x--;
	//			backDir_Red = 'd';
	//		}
	//		else if (GetNextBlockDir_Red(curPoint_Red.x, curPoint_Red.y) == 1) {
	//			curPoint_Red.y++;
	//			backDir_Red = 'l';
	//		}
	//		else if (GetNextBlockDir_Red(curPoint_Red.x, curPoint_Red.y) == 2) {
	//			curPoint_Red.x++;
	//			backDir_Red = 'u';
	//		}
	//		else if (GetNextBlockDir_Red(curPoint_Red.x, curPoint_Red.y) == 3) {
	//			curPoint_Red.y--;
	//			backDir_Red = 'r';
	//		}
	//		else if (GetNextBlockDir_Red(curPoint_Red.x, curPoint_Red.y) == 4) {
	//			return;
	//		}
	//	}
	//	int backT = 1;
	//	while (GetNextBlockDir_Red(curPoint_Red.x, curPoint_Red.y) == -1) {
	//		if (curPoint_Red.x == targetX_Red && curPoint_Red.y == targetY_Red) {
	//			alreadyFound = true;
	//			return;
	//		}
	//		FindWayBack_Red(backDir_Red, backT);   //此处需指定回退方向
	//	}
	//}

	while (!alreadyFound) {
		//cout << "1";

		curPoint_Red = searchedPoint_R[GetMinValuePoint_R()];
		while (IsPointFree_R(curPoint_Red) == -1) {                    //使curPoint就是权值最小的点
			searchedPoint_R[GetMinValuePoint_R()].free = false;
			curPoint_Red = searchedPoint_R[GetMinValuePoint_R()];
			//cout << "2";
		}

		switch (GetNextBlockDir_Red(curPoint_Red)) {
		case 0: {
			if (curPoint_Red.x == targetX_Red && curPoint_Red.y + 1 == targetY_Red) {
				alreadyFound = true;
			}
			if (map1[curPoint_Red.x][curPoint_Red.y + 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y + 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y + 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y + 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x =curPoint_Red.x ;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y + 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'l';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x + 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x + 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x + 1][curPoint_Red.y] != VISITED) {
				map1[curPoint_Red.x + 1][curPoint_Red.y] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x + 1;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'u';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x][curPoint_Red.y - 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y - 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y - 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y - 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y - 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'r';
				searchPointCount_R++;
			} 
			if (map1[curPoint_Red.x - 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x - 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x - 1][curPoint_Red.y] != VISITED) {
				map1[curPoint_Red.x - 1][curPoint_Red.y] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x - 1;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'd';
				searchPointCount_R++;
			}

			break;
		}
		case 1: {
			if (curPoint_Red.x + 1 == targetX_Red && curPoint_Red.y == targetY_Red) {
				alreadyFound = true;
			}
			
			if (map1[curPoint_Red.x][curPoint_Red.y + 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y + 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y + 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y + 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y + 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'l';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x + 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x + 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x + 1][curPoint_Red.y] != VISITED) {
				map1[curPoint_Red.x + 1][curPoint_Red.y] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x + 1;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'u';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x][curPoint_Red.y - 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y - 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y - 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y - 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y - 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'r';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x - 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x - 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x - 1][curPoint_Red.y] != VISITED) {
					map1[curPoint_Red.x - 1][curPoint_Red.y] = VISITED;
					searchedPoint_R[searchPointCount_R].x = curPoint_Red.x - 1;
					searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
					searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
					searchedPoint_R[searchPointCount_R].comeDir = 'd';
					searchPointCount_R++;
			}
			
			break;
		}
		case 2: {
			if (curPoint_Red.x == targetX_Red && curPoint_Red.y - 1 == targetY_Red) {
				alreadyFound = true;
			}
			
			if (map1[curPoint_Red.x][curPoint_Red.y + 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y + 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y + 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y + 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y + 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'l';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x + 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x + 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x + 1][curPoint_Red.y] != VISITED) {
				map1[curPoint_Red.x + 1][curPoint_Red.y] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x + 1;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'u';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x][curPoint_Red.y - 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y - 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y - 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y - 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y - 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'r';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x - 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x - 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x - 1][curPoint_Red.y] != VISITED) {
				map1[curPoint_Red.x - 1][curPoint_Red.y] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x - 1;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'd';
				searchPointCount_R++;
			}

			break;
		}
		case 3: {
			if (curPoint_Red.x - 1 == targetX_Red && curPoint_Red.y == targetY_Red) {
				alreadyFound = true;
			}
			
			if (map1[curPoint_Red.x][curPoint_Red.y + 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y + 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y + 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y + 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y + 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'l';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x + 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x + 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x + 1][curPoint_Red.y] != VISITED) {
				map1[curPoint_Red.x + 1][curPoint_Red.y] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x + 1;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'u';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x][curPoint_Red.y - 1] != WALL && map1[curPoint_Red.x][curPoint_Red.y - 1] != TELEPORT && map1[curPoint_Red.x][curPoint_Red.y - 1] != VISITED) {
				map1[curPoint_Red.x][curPoint_Red.y - 1] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y - 1;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'r';
				searchPointCount_R++;
			}
			if (map1[curPoint_Red.x - 1][curPoint_Red.y] != WALL && map1[curPoint_Red.x - 1][curPoint_Red.y] != TELEPORT && map1[curPoint_Red.x - 1][curPoint_Red.y] != VISITED) {
				map1[curPoint_Red.x - 1][curPoint_Red.y] = VISITED;
				searchedPoint_R[searchPointCount_R].x = curPoint_Red.x - 1;
				searchedPoint_R[searchPointCount_R].y = curPoint_Red.y;
				searchedPoint_R[searchPointCount_R].value = curPoint_Red.value + 1;
				searchedPoint_R[searchPointCount_R].comeDir = 'd';
				searchPointCount_R++;
			}

			break;
		}
		}
	 }
}


void RedGhost::RedGhostMove() {
	searchPointCount_R = 0;
	curMinValPointNum_R = 0;
	for (int i = 0; i < 400; ++i) searchedPoint_R[i] = emptySearchedPoint_R[i];

	for(int p = 0;p < 21;++p)
		for (int q = 0; q < 21; ++q) {
			if (map1[p][q] == WAY || map1[p][q] == VISITED || map1[p][q] == GHOST1) {
				map1[p][q] = EMPTY;
			}
		}

	curPoint_Red.x = this->x;
	curPoint_Red.y = this->y;

	searchedPoint_R[searchPointCount_R] = curPoint_Red;
	searchPointCount_R++;
	map1[x][y] = VISITED;

	if (ghostStatus == 1) {
		targetX_Red = pacManx;
		targetY_Red = pacMany;
	}
	else if (ghostStatus == 0) {
		targetX_Red = 10;
		targetY_Red = 9;
	}

	if ((curPoint_Red.x == targetX_Red && curPoint_Red.y == targetY_Red)) {
		x = curPoint_Red.x;
		y = curPoint_Red.y;
		return;
	}
	else if ((curPoint_Red.x == targetX_Red && curPoint_Red.y + 1 == targetY_Red)) {
		dir = 0;
	}
	else if ((curPoint_Red.x + 1 == targetX_Red && curPoint_Red.y == targetY_Red)) {
		dir = 1;
	}
	else if ((curPoint_Red.x == targetX_Red && curPoint_Red.y - 1 == targetY_Red)) {
		dir = 2;
	}
	else if ((curPoint_Red.x - 1 == targetX_Red && curPoint_Red.y == targetY_Red)) {
		dir = 3;
	}
	else {

		status = ghostStatus;
		FindPath_Red(status);
		//DrawGame();

		while (curPoint_Red.comeDir != 'm') {
			map1[curPoint_Red.x][curPoint_Red.y] = WAY;
			//DrawGame();
			switch (curPoint_Red.comeDir) {
			case 'r': {
				curPoint_Red = GetPoint_R(curPoint_Red.x, curPoint_Red.y + 1);
				break;
			}
			case 'd': {
				curPoint_Red = GetPoint_R(curPoint_Red.x + 1, curPoint_Red.y);
				break;
			}
			case 'l': {
				curPoint_Red = GetPoint_R(curPoint_Red.x, curPoint_Red.y - 1);
				break;
			}
			case 'u': {
				curPoint_Red = GetPoint_R(curPoint_Red.x - 1, curPoint_Red.y);
				break;
			}
			}
		}

		if (map1[this->x][this->y + 1] == WAY || map1[this->x][this->y + 1] == PACMAN) {
			dir = 0;
		}
		else if (map1[this->x + 1][this->y] == WAY || map1[this->x + 1][this->y] == PACMAN){
			dir = 1;
		}
		else if (map1[this->x][this->y - 1] == WAY || map1[this->x][this->y - 1] == PACMAN){
			dir = 2;
		}
		else if (map1[this->x - 1][this->y] == WAY || map1[this->x - 1][this->y] == PACMAN){
			dir = 3;
		}
		//DrawGame();
	}
	

	switch (dir) {
	case 0: {   //右
		if (map[x][y + 1] != WALL && map[x][y + 1] != TELEPORT) this->y += 1;
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
#include <iostream>
#include <windows.h>
#include<string>

#include"MAP.h"
#include"Ghost.h"
#include"PacMan.h"

using namespace std;

int map[21][21] = {
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, WALL, FOOD, FOOD, FOOD, WALL, WALL, WALL, WALL, WALL, FOOD, FOOD, FOOD, WALL, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, WALL, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, WALL, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, WALL, FOOD, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, FOOD, WALL, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, WALL, WALL, WALL, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, FOOD, FOOD, WALL, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, WALL, FOOD, FOOD, FOOD, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, EMPTY, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {TELEPORT, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, FOOD, WALL, FOOD, FOOD, FOOD, WALL, FOOD, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, TELEPORT},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, WALL},
    {WALL, FOOD, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, FOOD, WALL},
    {WALL, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, WALL},
    {WALL, FOOD, WALL, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, WALL, WALL, FOOD, WALL, FOOD, WALL, WALL, FOOD, WALL, WALL, FOOD, WALL, FOOD, WALL, WALL, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, FOOD, FOOD, WALL, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, WALL, FOOD, FOOD, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, WALL, FOOD, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, WALL, WALL, FOOD, WALL, WALL, WALL, FOOD, WALL, FOOD, WALL},
    {WALL, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, FOOD, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
};
int oldMap[21][21];
int map1[21][21];
int map2[21][21];
int map3[21][21];

int mode0;
int ghostStatus = 1;
int pacManx = 19;
int pacMany = 10;
boolean gameIsOn = false;     //t为游戏正在运行

RedGhost redGhost(10, 9, 1, 1, 0);
PinkGhost pinkGhost(10, 11, 1, 1, 2);
YellowGhost yellowGhost(10, 10, 1, 1, 3);
PacMan pacMan;

int getMin(int a, int b) {
    return a < b ? a : b;
}

bool PacManRedGhostCollise() {
    int redDistance = abs(redGhost.x - pacManx) + abs(redGhost.y - pacMany);
    if (redDistance <= 1) return true;
    return false;
}
bool PacManPinkGhostCollise() {
    int pinkDistance = abs(pinkGhost.x - pacManx) + abs(pinkGhost.y - pacMany);
    if (pinkDistance <= 1) return true;
    return false;
}
bool PacManYellowGhostCollise() {
    int yellowDistance = abs(yellowGhost.x - pacManx) + abs(yellowGhost.y - pacMany);
    if (yellowDistance <= 1) return true;
    return false;
}


//int pacManGhostDistance() {
//    int redDistance, pinkDistance, yellowDistance;
//    redDistance = abs(redGhost.x - pacManx) + abs(redGhost.y - pacMany);
//    pinkDistance = abs(pinkGhost.x - pacManx) + abs(pinkGhost.y - pacMany);
//    yellowDistance = abs(yellowGhost.x - pacManx) + abs(yellowGhost.y - pacMany);
//
//    return getMin(getMin(redDistance, pinkDistance), yellowDistance);
//}

bool GameOn() {    //游戏进行函数
    //复位
    for (int m = 0; m < 21; ++m) {
        for (int n = 0; n < 21; ++n) {
            if (map[m][n] != WALL && map[m][n] != TELEPORT && !((m == 10 && (n > 0 && n < 7)) || (m == 10 && (n > 13 && n < 20))) && !(m == 9 && n == 10)) { 
                map[m][n] = FOOD;
            }
        }
    }
    for (int m = 0; m < 21; ++m) {
        for (int n = 0; n < 21; ++n) {
            if (map[m][n] != WALL && map[m][n] != TELEPORT) {   // && !((m == 10 && (n > 0 && n < 7)) || (m == 10 && (n > 13 && n < 20)))
                map1[m][n] = EMPTY;
                map2[m][n] = EMPTY;
            }
        }
    }

    map[1][1] = PILL;
    map[1][19] = PILL;
    map[19][1] = PILL;
    map[19][19] = PILL;

    mode0 = 0;
    ghostStatus = 1;
    pacDir = 3;
    eatFood = 0;

    pacManx = 19; pacMany = 10;
    pacMan.x = 19; pacMan.y = 10;
    redGhost.x = 10;  redGhost.y = 9; redGhost.dir = 0;
    pinkGhost.x = 10;  pinkGhost.y = 11; pinkGhost.dir = 2;
    yellowGhost.x = 10;  yellowGhost.y = 10; yellowGhost.dir = 3;
    map[10][9] = GHOST1; map[10][10] = GHOST2; map[10][11] = GHOST3;
    map[19][10] = PACMAN;

    system("cls");
    DrawGame();
    Sleep(500);

    bool isPinkMovable = true, isRedMovable = true, isYellowMovable = true;
    int isFood1 = 0, isFood2 = 0, isFood3 = 0;   //0为empty   1为FOOD   2为PILL
    while (gameIsOn) {

        for (int m = 0; m < 21; ++m) {
            for (int n = 0; n < 21; ++n) {
                oldMap[m][n] = map[m][n];
            }
        }

        pacMan.PacManMove();

        int tmpx1 = redGhost.x, tmpy1 = redGhost.y;
        int tmpx2 = pinkGhost.x, tmpy2 = pinkGhost.y;
        int tmpx3 = yellowGhost.x, tmpy3 = yellowGhost.y;


        if (isPinkMovable) {
            pinkGhost.PinkGhostMove();
        }
        if (isYellowMovable) {
            yellowGhost.YellowGhostMove();
        }
        if (isRedMovable) {
            redGhost.RedGhostMove();
        }
        
        
        if(isFood1 == 0) map[tmpx1][tmpy1] = EMPTY;
        else if(isFood1 == 1) map[tmpx1][tmpy1] = FOOD;
        else if (isFood1 == 2) map[tmpx1][tmpy1] = PILL;

        if (isFood2 == 0) map[tmpx2][tmpy2] = EMPTY;
        else if (isFood2 == 1) map[tmpx2][tmpy2] = FOOD;
        else if (isFood2 == 2) map[tmpx2][tmpy2] = PILL;

        if (isFood3 == 0) map[tmpx3][tmpy3] = EMPTY;
        else if (isFood3 == 1) map[tmpx3][tmpy3] = FOOD;
        else if (isFood3 == 2) map[tmpx3][tmpy3] = PILL;
        
        
        map1[tmpx1][tmpy1] = EMPTY;
        map2[tmpx2][tmpy2] = EMPTY;
        map3[tmpx3][tmpy3] = EMPTY;

        if (map[redGhost.x][redGhost.y] == EMPTY) isFood1 = 0;
        else if (map[redGhost.x][redGhost.y] == FOOD) isFood1 = 1;
        else if (map[redGhost.x][redGhost.y] == PILL) isFood1 = 2;

        if (map[pinkGhost.x][pinkGhost.y] == EMPTY) isFood2 = 0;
        else if (map[pinkGhost.x][pinkGhost.y] == FOOD) isFood2 = 1;
        else if (map[pinkGhost.x][pinkGhost.y] == PILL) isFood2 = 2;

        if (map[yellowGhost.x][yellowGhost.y] == EMPTY) isFood3 = 0;
        else if (map[yellowGhost.x][yellowGhost.y] == FOOD) isFood3 = 1;
        else if (map[yellowGhost.x][yellowGhost.y] == PILL) isFood3 = 2;

        map[redGhost.x][redGhost.y] = GHOST1;
        map1[redGhost.x][redGhost.y] = GHOST1;
        map[pinkGhost.x][pinkGhost.y] = GHOST2;
        map2[pinkGhost.x][pinkGhost.y] = GHOST2;
        map[yellowGhost.x][yellowGhost.y] = GHOST3;
        map3[yellowGhost.x][yellowGhost.y] = GHOST3;

       /* if (map[redGhost.x][redGhost.y] != WALL && map[redGhost.x][redGhost.y] != TELEPORT) {
            map[redGhost.x][redGhost.y] = GHOST1;
            map2[redGhost.x][redGhost.y] = GHOST1;
        }
        else {
            map[tmpx1][tmpy1] = GHOST1;
        }
        if (map[redGhost.x][redGhost.y] != WALL && map[redGhost.x][redGhost.y] != TELEPORT) {
            map[pinkGhost.x][pinkGhost.y] = GHOST2;
            map2[pinkGhost.x][pinkGhost.y] = GHOST2;
        }
        else {
            map2[tmpx2][tmpy2] = GHOST2;
        }
        if (map[redGhost.x][redGhost.y] != WALL && map[redGhost.x][redGhost.y] != TELEPORT) {
            map[yellowGhost.x][yellowGhost.y] = GHOST3;
            map2[yellowGhost.x][yellowGhost.y] = GHOST3;
        }
        else {
            map[tmpx3][tmpy3] = GHOST3;
        }*/
       /* if ((redGhost.x == pacManx && redGhost.y == pacMany) || (pinkGhost.x == pacManx && pinkGhost.y == pacMany) || (yellowGhost.x == pacManx && yellowGhost.y == pacMany)) {
            return false;
        }*/

        //if (pacManGhostDistance() <= 1) return false;

        if (PacManRedGhostCollise()) {
            if (ghostStatus == 1) return false;
            else if (ghostStatus == 0) {
                map[redGhost.x][redGhost.y] = EMPTY;
                redGhost.x = 10;
                redGhost.y = 9; 
                redGhost.dir = 0;
                isFood1 = 0;    //否则可能会在幽灵出生点生成食物
                map[10][9] = GHOST1;
                isRedMovable = false;
                eatFood += 10;
            }
        }
        if (PacManPinkGhostCollise()) {
            if (ghostStatus == 1) return false;
            else if (ghostStatus == 0) {
                map[redGhost.x][redGhost.y] = EMPTY;
                pinkGhost.x = 10;
                pinkGhost.y = 11;
                pinkGhost.dir = 2;
                map[10][11] = GHOST2;
                isFood2 = 0;
                isPinkMovable = false;
                eatFood += 10;
            }
        }
        if (PacManYellowGhostCollise()) {
            if (ghostStatus == 1) return false;
            else if (ghostStatus == 0) {
                map[yellowGhost.x][yellowGhost.y] = EMPTY;
                yellowGhost.x = 10;
                yellowGhost.y = 10;
                yellowGhost.dir = 3;
                isFood3 = 0;
                map[10][10] = GHOST3;
                isYellowMovable = false;
                eatFood += 10;
            }
        }

        for (int m = 0; m < 21; ++m) {
            for (int n = 0; n < 21; ++n) {
                if (map2[m][n] == WALL && map[m][n] != WALL) return false;
            }
        }
        map[pacManx][pacMany] = PACMAN;

        //system("cls");
        //DrawGame();
        DrawGameNoFlash();

        gotoxy(22,0);
        cout << "ur score:" << eatFood << endl;
        cout << "PILL effect countdown:" << mode0 << endl;
        cout << "ghostStatus:" << ghostStatus << endl;
        if (eatFood >= 100) return true;

        if (mode0 > 0) mode0 -= 500;
        if (mode0 <= 0) {
            isRedMovable = true;
            isPinkMovable = true;
            isYellowMovable = true;
            ghostStatus = 1;
        }
            
        Sleep(500);
    }
}

int main(){
    //cout << "℃○﹒．⊕⊙●◎○Οо" << endl;
    
    string str;

    HideCursor(true);    //隐藏光标

    //pinky的地图
    for (int m = 0; m < 21; ++m)
        for (int n = 0; n < 21; ++n) {
            if (map[m][n] == FOOD || map[m][n] == PILL) {
                map1[m][n] = EMPTY;
                map2[m][n] = EMPTY;
                map3[m][n] = EMPTY;
            }
            else {
                map1[m][n] = map[m][n];
                map2[m][n] = map[m][n];
                map3[m][n] = map[m][n];
            }
        }
            

    gameIsOn = true;
    //①②③④⑤⑥⑦⑧⑨
    //map[redGhost.x][redGhost.y] = GHOST;
    cout << "type in \"s\" to start" << endl;
    cout << "ur Goal : get 100 points" << endl;
    cout << "GHOST ① : always follow u" << endl;
    cout << "GHOST ② : predict ur move in someway" << endl;
    cout << "GHOST ③ : move randomly" << endl;
    cout << "1 food = 1 point" << endl;
    cout << "1 ghost = 10 point" << endl;


    while (cin >> str) {
        if (str == "s") {
            for (int m = 0; m < 21; ++m)
                for (int n = 0; n < 21; ++n)
                    map[m][n] = map2[m][n];
            if (GameOn()) cout << "You Win" << endl;
            else {
                system("cls");
                DrawGame();

                cout << "ur score:" << eatFood << endl;
                cout << "You Lost" << endl;
            }
        }
        else cout << "unknow cmd" << endl;

        cout << "type in \"s\" to restart" << endl;
        cout << "ur Goal : get 100 points" << endl;
        cout << "GHOST ① : always follow u" << endl;
        cout << "GHOST ② : predict ur move in someway" << endl;
        cout << "GHOST ③ : move randomly" << endl;
        cout << "1 food = 1 point" << endl;
        cout << "1 ghost = 10 point" << endl;
    }
}
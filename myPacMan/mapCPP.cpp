#include<iostream>
#include<Windows.h>

#include"MAP.h"

using namespace std;

//隐藏光标
void HideCursor(bool Visible) {
    CONSOLE_CURSOR_INFO Cursor;
    Cursor.bVisible = !Visible;
    Cursor.dwSize = sizeof(Cursor);
    HANDLE Hand = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(Hand, &Cursor);
}

//光标置于（x，y）
void gotoxy(int x, int y) {
    COORD pos = { y, x };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void DrawGame() {
    for (int m = 0; m < 21; ++m) {
        for (int n = 0; n < 21; ++n) {
            if (map[m][n] == WALL) { cout << "■";}
            else if (map[m][n] == FOOD) { cout << "·"; }
            else if (map[m][n] == PILL) { cout << "⊕"; }
            else if (map[m][n] == VISITED) { cout << "  "; }
            else if (map[m][n] == GHOST1) { cout << "①"; }
            else if (map[m][n] == GHOST2) { cout << "②"; }
            else if (map[m][n] == GHOST3) { cout << "③"; }
            else if (map[m][n] == WAY) { cout << "  "; }  //①②③④⑤⑥⑦⑧⑨ 
            else if (map[m][n] == PACMAN) { cout << "●"; } //○●℃○﹒．⊕⊙●◎○Οо 
            else if (map[m][n] == TELEPORT) { cout << "○"; }
            else if (map[m][n] == EMPTY) { cout << "  "; }
        }
        cout << endl;
    }

    //for (int m = 0; m < 21; ++m) {
    //    for (int n = 0; n < 21; ++n) {
    //        if (map2[m][n] == WALL) {
    //            cout << "■";
    //        }
    //        else if (map2[m][n] == FOOD) {
    //            cout << "  ";
    //        }
    //        else if (map2[m][n] == VISITED) {
    //            cout << "④";   //④
    //        }
    //        else if (map2[m][n] == GHOST) {
    //            cout << "＠";
    //        }
    //        else if (map2[m][n] == WAY) {
    //            cout << "②";   //②
    //        }
    //        else if (map2[m][n] == PACMAN) {
    //            cout << "⑩";
    //        }
    //        else if (map2[m][n] == TELEPORT) {
    //            cout << "O ";
    //        }
    //    }
    //    cout << endl;
    //}
}

void DrawGameNoFlash() {
    for (int m = 0; m < 21; ++m) {
        for (int n = 0; n < 21; ++n) {
            if (oldMap[m][n] != map[m][n]) {
                int tmpPos = 0;
                //DrawGame();
                for (int i = 0; i < n; ++i) {
                    tmpPos += 2;
                }
                gotoxy(m,tmpPos);
                if (map[m][n] == WALL) { cout << "■"; }
                if (map[m][n] == FOOD) { cout << "·"; }
                if (map[m][n] == PILL) { cout << "⊕"; }
                if (map[m][n] == VISITED) { cout << "  "; }
                if (map[m][n] == GHOST1) { cout << "①"; }
                if (map[m][n] == GHOST2) { cout << "②"; }
                if (map[m][n] == GHOST3) { cout << "③"; }
                if (map[m][n] == WAY) { 
                    cout << "  ";
                }  //①②③④⑤⑥⑦⑧⑨ 
                if (map[m][n] == PACMAN) { 
                    cout << "●"; 
                } //○●℃○﹒．⊕⊙●◎○Οо 
                if (map[m][n] == TELEPORT) { cout << "○"; }
                if (map[m][n] == EMPTY) { cout << "  "; }
            }
        }
    }
}

void DrawGame2() {
    for (int m = 0; m < 21; ++m) {
        for (int n = 0; n < 21; ++n) {
            if (map2[m][n] == WALL) {
                cout << "■";
            }
            else if (map2[m][n] == FOOD) {
                cout << "·";
            }
            else if (map2[m][n] == VISITED) {
                cout << "④";
            }
            else if (map2[m][n] == GHOST1) {
                cout << "①";
            }
            else if (map2[m][n] == GHOST2) {
                cout << "②";
            }
            else if (map2[m][n] == GHOST3) {
                cout << "③";
            }
            else if (map2[m][n] == WAY) {
                cout << "@ ";   //①②③④⑤⑥⑦⑧⑨
            }
            else if (map2[m][n] == PACMAN) {
                cout << "●";   //○●
            }
            else if (map2[m][n] == TELEPORT) {
                cout << "○";
            }
            else if (map2[m][n] == EMPTY) {
                cout << "  ";
            }
        }
        cout << endl;
    }

    //for (int m = 0; m < 21; ++m) {
    //    for (int n = 0; n < 21; ++n) {
    //        if (map2[m][n] == WALL) {
    //            cout << "■";
    //        }
    //        else if (map2[m][n] == FOOD) {
    //            cout << "  ";
    //        }
    //        else if (map2[m][n] == VISITED) {
    //            cout << "④";   //④
    //        }
    //        else if (map2[m][n] == GHOST) {
    //            cout << "＠";
    //        }
    //        else if (map2[m][n] == WAY) {
    //            cout << "②";   //②
    //        }
    //        else if (map2[m][n] == PACMAN) {
    //            cout << "⑩";
    //        }
    //        else if (map2[m][n] == TELEPORT) {
    //            cout << "O ";
    //        }
    //    }
    //    cout << endl;
    //}
}
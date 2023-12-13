#include <iostream>
#include <graphics.h>

using namespace std;

const int X_MIN = 50;
const int Y_MIN = 50;
const int X_MAX = 400;
const int Y_MAX = 300;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

void cohenSutherland(int& x1, int& y1, int& x2, int& y2) {
    int code1 = 0, code2 = 0;

    auto calculateCode = [](int x, int y) {
        int code = INSIDE;

        if (x < X_MIN)
            code |= LEFT;
        else if (x > X_MAX)
            code |= RIGHT;

        if (y < Y_MIN)
            code |= BOTTOM;
        else if (y > Y_MAX)
            code |= TOP;

        return code;
    };

    while (true) {
        code1 = calculateCode(x1, y1);
        code2 = calculateCode(x2, y2);

        if (!(code1 | code2)) {
            line(x1, y1, x2, y2);
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int codeOut = code1 ? code1 : code2;

            int x, y;
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
            } else {
                x2 = x;
                y2 = y;
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");

    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
    int x1 = 60, y1 = 40, x2 = 300, y2 = 200;
    cohenSutherland(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}

#include "bigProblemsPaint.h"

void lineDots(vector<string> &canvas, int x1, int y1, int x2, int y2, char symbol){
    if(x1 >= 0 && x1 < itc_len(canvas[0]) && y1 >= 0 && y1 < canvas.size())
        canvas[y1][x1] = symbol;
    if(x2 >= 0 && x2 < itc_len(canvas[0]) && y2 >= 0 && y2 < canvas.size())
        canvas[y2][x2] = symbol;
}

void SetCursorSymmetryX(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    lineDots(canvas, x, y, x0 * 2 - x, y, symbol);
}

void SetCursorSymmetryY(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    lineDots(canvas, x, y, x, 2 * y0 - y, symbol);
}

void SetPixelSymmetry14(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    if(x0 > y0){
        x -= abs(x0 - y0);
        y += abs(x0 - y0);
    }
    else{
        x += abs(x0 - y0);
        y -= abs(x0 - y0);
    }

    lineDots(canvas, y, x, 2 * y0 - y, x, symbol);
    lineDots(canvas, y, x, y, x0 * 2 - x, symbol);
    lineDots(canvas, y, x0 * 2 - x, 2 * y0 - y, x0 * 2 - x, symbol);
    lineDots(canvas, 2 * y0 - y, x, 2 * y0 - y, x0 * 2 - x, symbol);
}

void SetPixel14(vector<string> &canvas, int x, int y, int radius, char symbol){
    if(x >= 0 && y >= 0 && x < itc_len(canvas[0]) && y < canvas.size())
        canvas[y][x] = symbol;
    if(x + radius >= 0 && y + radius >= 0 && x + radius < itc_len(canvas[0]) && y + radius < canvas.size())
        canvas[y + radius][x + radius] = symbol;
    if(x >= 0 && y + radius * 2 >= 0 && x < itc_len(canvas[0]) && y + radius * 2 < canvas.size())
        canvas[y + radius * 2][x] = symbol;
    if(x - radius >= 0 && y + radius >= 0 && x - radius < itc_len(canvas[0]) && y + radius < canvas.size())
        canvas[y + radius][x - radius] = symbol;
}

void SetPixel18(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    SetCursorSymmetryX(canvas, x, y, x0, y0, radius, symbol);//up left

    SetCursorSymmetryY(canvas, x, y, x0, y0, radius, symbol);//bottom right

    SetCursorSymmetryX(canvas, x, 2 * y0 - y, x0, y0, radius, symbol);//bottom left

    SetCursorSymmetryY(canvas, x0 * 2 - x, y, x0, y0, radius, symbol);

    SetPixelSymmetry14(canvas, x0 * 2 - x, y, x0, y0, radius, symbol);//bottom left
}

void Ring(vector<string> &canvas, float Fx0, float Fy0, float Fradius, char ringSymbol){
    int x0 = round(Fx0), y0 = round(Fy0), radius = round(Fradius);
    int x = x0;
    int y = y0 - radius;
    int counter = x;
    int f = 1 - radius;
    int incrE = 3;
    int incrSE = 5 - 2 * radius;
    SetPixel14(canvas, x, y, radius, ringSymbol);
    while(counter - (x0 - y0) > y){
        if(f > 0){
            y++;
            f += incrSE;
            incrSE += 2;
        }
        else{
            f += incrE;
            incrSE += 2;
        }
        incrE += 2;
        x++;
        counter--;
        SetPixel18(canvas, x, y, x0, y0, radius, ringSymbol);
    }
}

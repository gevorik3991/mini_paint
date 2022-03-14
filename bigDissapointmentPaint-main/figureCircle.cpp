#include "bigProblemsPaint.h"

void intLine(vector<string> &canvas, int x, int y, int intX2, int intY2, int intX3, int intY3, char m){
    float x2 = (float)intX2, y2 = (float)intY2, x3 = (float)intX3, y3 = (float)intY3;
    float raznx, razny, sdvigx, sdvigy, s, f;
    for (int k = 0; k < y; k++)
    {
        for (int i = 0; i < x; i++)
        {
                if (x3 > x2)
                {
                    //cout<<1;
                    if (y3 > y2)
                    {
                        raznx = x3 - x2;
                        razny = y3 - y2;
                        sdvigx = raznx / razny;
                        sdvigy = razny / raznx;
                        s = (k - y2) * sdvigx;
                        if (int(s*10)%10 > 5)
                            s++;
                        f = (i - x2) * sdvigy;
                        if (int(f*10)%10 > 5 )
                            f++;
                        if ((i == x2 + int(s) || k == y2 + int(f)) && k >= y2 && k <= y3 && i >= x2 && i <= x3)
                            canvas[k][i] = m;
                    }
                    else
                    {
                        raznx = x3 - x2;
                        razny = y2 - y3;
                        sdvigx = raznx / razny;
                        sdvigy = razny / raznx;
                        s = (k - y3) * sdvigx;
                        if (int(s*10)%10 > 5)
                            s++;
                        f = (i - x3) * sdvigy;
                        if (int(f*10)%10 > 5 )
                            f++;
                        if ((i == x3 - int(s) || k == y3 - int(f)) && k <= y2 && k >= y3 && i >= x2 && i <= x3)
                            canvas[k][i] = m;
                    }
                }
                else if (x3 < x2)
                {
                    if (y3 > y2)
                    {
                        raznx = x2 - x3;
                        razny = y3 - y2;
                        sdvigx = raznx / razny;
                        sdvigy = razny / raznx;
                        s = (k - y2) * sdvigx;
                        if (int(s*10)%10 > 5)
                            s++;
                        f = (x2 - i) * sdvigy;
                        if (int(f*10)%10 > 5 )
                            f++;
                        if ((i == x2 - int(s) || k == y2 + int(f)) && k >= y2 && k <= y3 && i <= x2 && i >= x3)
                            canvas[k][i] = m;
                    }
                    else
                    {
                        raznx = x2 - x3;
                        razny = y2 - y3;
                        sdvigx = raznx / razny;
                        sdvigy = razny / raznx;
                        s = (k - y3) * sdvigx;
                        if (int(s*10)%10 > 5)
                            s++;
                        f = (i - x3) * sdvigy;
                        if (int(f*10)%10 > 5 )
                            f++;
                        if ((i == x3 + int(s) || k == y3 + int(f)) && k <= y2 && k >= y3 && i <= x2 && i >= x3)
                            canvas[k][i] = m;
                    }
                }
                else
                {
                    if (y2 > y3)
                    {
                        if (i == x2 && k >= y3 && k <= y2)
                            canvas[k][i] = m;
                    }
                    else
                    {
                        if (i == x2 && k <= y3 && k >= y2)
                            canvas[k][i] = m;
                    }
                }
        }
    }
}

void SetCursorSymmetryXC(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    intLine(canvas, itc_len(canvas[0]), canvas.size(), x, y, x0 * 2 - x, y, symbol);
}

void SetCursorSymmetryYC(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    intLine(canvas, itc_len(canvas[0]), canvas.size(), x, y, x, 2 * y0 - y, symbol);
}

void SetPixelSymmetry14C(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    int x1 = x, y1 = y;
    if(x0 > y0){
        x -= abs(x0 - y0);
        y += abs(x0 - y0);
    }
    else if(y0 > x0){
        x += abs(x0 - y0);
        y -= abs(x0 - y0);
    }
    intLine(canvas, itc_len(canvas[0]), canvas.size(), y, x, 2 * y0 - y, x, symbol);
    intLine(canvas, itc_len(canvas[0]), canvas.size(), y, x, y, x0 * 2 - x, symbol);
    intLine(canvas, itc_len(canvas[0]), canvas.size(), y, x0 * 2 - x, 2 * y0 - y, x0 * 2 - x, symbol);
    intLine(canvas, itc_len(canvas[0]), canvas.size(), 2 * y0 - y, x, 2 * y0 - y, x0 * 2 - x, symbol);
}

void SetPixel14C(vector<string> &canvas, int x, int y, int radius, char symbol){
    intLine(canvas, itc_len(canvas[0]), canvas.size(), x, y, x, y + radius * 2, symbol);
    intLine(canvas, itc_len(canvas[0]), canvas.size(), x - radius, y + radius, x + radius, y + radius, symbol);
}

void SetPixel18C(vector<string> &canvas, int x, int y, int x0, int y0, int radius, char symbol){
    SetCursorSymmetryXC(canvas, x, y, x0, y0, radius, symbol);//up left

    SetCursorSymmetryYC(canvas, x, y, x0, y0, radius, symbol);//bottom right

    SetCursorSymmetryXC(canvas, x, 2 * y0 - y, x0, y0, radius, symbol);//bottom left

    SetCursorSymmetryYC(canvas, x0 * 2 - x, y, x0, y0, radius, symbol);

    SetPixelSymmetry14C(canvas, x0 * 2 - x, y, x0, y0, radius, symbol);//bottom left
}

void Circle(vector<string> &canvas, float Fx0, float Fy0, float Fradius, char ringSymbol){
    int x0 = round(Fx0), y0 = round(Fy0), radius = round(Fradius);
    int x = x0;
    int y = y0 - radius;
    int counter = x;
    int f = 1 - radius;
    int incrE = 3;
    int incrSE = 5 - 2 * radius;
    SetPixel14C(canvas, x, y, radius, ringSymbol);
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
        SetPixel18C(canvas, x, y, x0, y0, radius, ringSymbol);
    }
}

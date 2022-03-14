#include "bigProblemsPaint.h"

void Line(vector<string> &canvas, int x, int y, float x2, float y2, float x3, float y3, char m){
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

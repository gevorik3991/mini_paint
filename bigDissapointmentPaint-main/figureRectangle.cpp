#include "bigProblemsPaint.h"

void rectangle(vector<string> &canvas, int x, int y, int x1, int y1, int width, int height, char m){
    for (int k = 0; k < y; k++)
    {
        for (int i = 0; i < x; i++)
        {
            if ((i >= x1 && i < x1 + width - 1 && k == y1) || ((i == x1 || i == x1 + width - 1) && (k >= y1 && k < y1 + height - 1)) || (i >= x1 && i < x1 + width && k == y1 + height - 1))
                    canvas[k][i] = m;
        }
    }
}

void Rectangle(vector<string> &canvas, int x, int y, int x1, int y1, int width, int height, char m){
    for (int k = 0; k < y; k++)
    {
        for (int i = 0; i < x; i++)
        {
                if ((k >= y1 && k < y1 + height) && (i >= x1  && i < x1 + width))
                    canvas[k][i] = m;
        }
    }
}

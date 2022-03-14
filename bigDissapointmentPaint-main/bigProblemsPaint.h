#ifndef BIGPROBLEMSPAINT_H_INCLUDED
#define BIGPROBLEMSPAINT_H_INCLUDED

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void Rectangle(vector<string> &canvas, int x, int y, int x1, int y1, int width, int height, char m);
void rectangle(vector<string> &canvas, int x, int y, int x1, int y1, int width, int height, char m);

void Ring(vector<string> &canvas, float Fx0, float Fy0, float Fradius, char ringSymbol);
void Circle(vector<string> &canvas, float Fx0, float Fy0, float Fradius, char ringSymbol);

void Line(vector<string> &canvas, int x, int y, float x2, float y2, float x3, float y3, char m);

int itc_len(string str);
int itc_countWords(string str);
int itc_toInt(string s);
void itc_swap(int &a, int &b);
float itc_toFloat(string s);
string itc_removeSpace(string str);
string itc_rmFreeSpace(string str);

#endif // BIGPROBLEMSPAINT_H_INCLUDED

#include "bigProblemsPaint.h"

void gotoxy(int x, int y){
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void Background(vector<string> &canvas, int width, int height, string backgroundSymbol){
    for(int y = 0; y < height; y++){
        canvas.push_back("");
        for(int x = 0; x < width; x++){
            canvas[y] += backgroundSymbol;
        }
    }
}

vector<string> split(const vector<string> &commandsList, int lineIndex){
    int length = itc_len(commandsList[lineIndex]);
    string line = commandsList[lineIndex];
    string word;
    vector<string> words;
    for(int i = 0; i < length; i++){
        if(line[i] != ' ')
            word += line[i];
        else{
            words.push_back(word);
            word = "";
        }
    }
    words.push_back(word);
    return words;
}

void Figures(vector<string> &canvas, const vector<string> &commandsList){
    vector<string> words = split(commandsList, 0);
    int x = itc_toInt(words[0]);
    int y = itc_toInt(words[1]);
    string z = words[2];
    char m;
    Background(canvas, x, y, z);
    string a;
    int x1, y1, width, height;
    float x2, y2, x3, y3, radius;
    for(int i = 1; i < commandsList.size(); i++){
        words = split(commandsList, i);
        a = words[0];
        if(a == "r" || a == "R"){
            x1 = itc_toInt(words[1]);
            y1 = itc_toInt(words[2]);
            width = itc_toInt(words[3]);
            height = itc_toInt(words[4]);
            m = words[5][0];
            if(a == "r")
                rectangle(canvas, x, y, x1, y1, width, height, m);
            else
                Rectangle(canvas, x, y, x1, y1, width, height, m);
        }
        else if(a == "L"){
            x2 = itc_toFloat(words[1]);
            y2 = itc_toFloat(words[2]);
            x3 = itc_toFloat(words[3]);
            y3 = itc_toFloat(words[4]);
            m = words[5][0];
            Line(canvas, x, y, x2, y2, x3, y3, m);
        }
        else if(a == "c" || a == "C"){
            x2 = itc_toFloat(words[1]);
            y2 = itc_toFloat(words[2]);
            radius = itc_toFloat(words[3]);
            m = words[4][0];
            if(a == "c")
                Ring(canvas, x2, y2, radius, m);
            else
                Circle(canvas, x2, y2, radius, m);
        }
    }
}

bool checkExtension(string s){
    int length = itc_len(s);
    if(s[length - 3] == '.' && s[length - 2] == 'i' && s[length - 1] == 't')
        return true;
    return false;
}

bool checkName(string s){
    string newString = "";
    for(int i = 0; i < itc_len(s) - 3; i++)
        newString += s[i];
    if(newString == "operation")
        return true;
    return false;
}

void printCanvas(const vector<string> &arr){
    int length = itc_len(arr[0]);
    for(int  y = 0; y < arr.size(); y++){
        for(int x = 0; x < length; x++){
            cout << arr[y][x];
        }
    cout << endl;
    }
}

void printArray(const vector<string> &arr){
    for(int  i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
    cout << endl;
}

bool isNumber(string s){
    int length = itc_len(s);
    int numberOfDots = 0;
    for(int i = 0; i < length; i++){
        if(!(s[i] >= 48 && s[i] <= 57)){
            if(s[i] == '.'){
                numberOfDots++;
                if(numberOfDots > 1 || i == 0)
                    return false;
            }
            else
                return false;

        }
        if(length >= 2){
            if(s[0] == '0' && s[1] != '.')
                return false;
        }
    }
    return true;
}

bool TrueIntFalseFloat(string s){
    int length = itc_len(s);
    int numberOfDots = 0;
    for(int i = 0; i < length; i++){
        if(!(s[i] >= 48 && s[i] <= 57)){
            if(s[i] == '.'){
                numberOfDots++;
                if(numberOfDots > 1 || i == 0)
                    return false;
            }
            else
                return false;

        }
        if(length >= 2){
            if(s[0] == '0' && s[1] != '.')
                return false;
        }
    }
    if(numberOfDots == 0)
        return true;
    return false;
}

bool checkLines(const vector<string> &commandsList){
    vector<string> words;
    for(int lineIndex = 0; lineIndex < commandsList.size(); lineIndex++){
        if(lineIndex == 0){
            vector<string> words = split(commandsList, 0);
            if(words.size() != 3){
                printArray(words);
                return false;
            }
            if(!isNumber(words[0]) || !isNumber(words[1]) || itc_len(words[2]) != 1 || !TrueIntFalseFloat(words[0]) || !TrueIntFalseFloat(words[1]) || itc_toInt(words[0]) > 300 || itc_toInt(words[1]) > 300){
                cout << isNumber(words[0]) << " " << isNumber(words[1]) << " " << itc_len(words[2]);
                return false;
            }
        }
        if(lineIndex > 0){
            vector<string> words = split(commandsList, lineIndex);
            if(!(((words[0] == "r" || words[0] == "R" || words[0] == "L") && (words.size() == 6)) || ((words[0] == "c" || words[0] == "C") && (words.size() == 5)))){
                cout << words[0] << " " << words.size();
                return false;
            }
            for(int i = 1; i < words.size() - 1; i++){
                if((i != words.size() - 1 && !isNumber(words[i])) ||
                   (i != words.size() - 1 && isNumber(words[i]) && TrueIntFalseFloat(words[i]) && (words[0] == "L" || words[0] == "c" || words[0] == "C")) ||
                   (i != words.size() - 1 && isNumber(words[i]) && !TrueIntFalseFloat(words[i]) && (words[0] == "r" || words[0] == "R"))){
                    cout << i << " " << words.size() - 1 << " " << isNumber(words[i]);
                    return false;
                }
            }
            if(itc_len(words[words.size() - 1]) != 1){
                cout << words[words.size() - 1];
                return false;
            }
        }
    }
    return true;
}

void readFromFile(vector<string> &commandsList, ifstream &inputFromFile){
    string buffer;
    for(getline(inputFromFile, buffer); !inputFromFile.eof(); getline(inputFromFile, buffer))
        commandsList.push_back(itc_rmFreeSpace(buffer));
    getline(inputFromFile, buffer);
    if(buffer != "")
        commandsList.push_back(itc_rmFreeSpace(buffer));
}

int main(int argc, char *argv[])
{
    vector<string> canvas;
    vector<string> commandsList;
    ifstream inputFromFile;
    int canvasSizeX, canvasSizeY;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


    SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_RED);
    if(argc > 2)
        cout << "ERROR: There are too many arguments!";
    else if(argc == 1)
        cout << "ERROR: There are too few arguments!";
    else{
        ifstream inputFromFile(argv[1]);
        if(!checkExtension(argv[1]))
            cout << "ERROR: Incorrect file extension!";
        else if(!checkName(argv[1]))
            cout << "ERROR: Incorrect file name!";
        else if(!inputFromFile)
            cout << "ERROR: File not found!";
        else{
            readFromFile(commandsList, inputFromFile);
            if(checkLines(commandsList)){
                SetConsoleTextAttribute(console, FOREGROUND_GREEN);
                cout << "Correct" << endl;
                Figures(canvas, commandsList);
                cout << endl;
                printCanvas(canvas);
            }
            else
                cout << "Incorrect";
        }
    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}






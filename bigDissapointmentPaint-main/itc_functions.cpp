#include "bigProblemsPaint.h"

int itc_len(string str){
    int kol = 0;
    for(int i = 0; str[i] != '\0'; i++){
        kol++;
    }
    return kol;
}

string itc_removeSpace(string str){
    string newstr = "";
    for(unsigned long long i = 0; i < itc_len(str); i++){
        if(str[i] != ' ') newstr += str[i];
    }
    return newstr;
}

string itc_rmFreeSpace(string str){
    if(itc_len(str) == 0) return "";
    string newstr = "";
    string answ = "";
    bool wasOnSpace = false;
    bool flag = false;
    for(long long i = 0; i < itc_len(str); i++){
        if(str[0] == ' ' && !flag){
            while(str[i] == ' '){
                i++;
            }
            flag = true;
        }
        if(str[i] == ' ' && !wasOnSpace) {
            wasOnSpace = true;
            newstr += ' ';
        }
        if(wasOnSpace && str[i] != ' ') wasOnSpace = false;
        if(!wasOnSpace) newstr += str[i];
    }
    if(newstr[itc_len(newstr) - 1] == ' '){
        for(long long i = 0; i < itc_len(newstr) - 1; i++) answ += newstr[i];
    }
    else answ = newstr;
    return answ;
}

int itc_countWords(string str){
    int words = 0;
    bool onWord = false;
    for(long long i = 0; i < itc_len(str); i++){
        if(str[i] == ' ') onWord = false;
        if(str[i] != ' ') onWord = true;
        if(str[i] == ' ' && onWord == true){
            while(str[i] != ' ' && str[i] != '\0'){
                i++;
            }
            onWord = false;
        }
        if((str[i + 1] == ' ' || str[i + 1] == '\0') && onWord == true){
            words++;
        }
    }
    return words;
}

int itc_toInt(string s){
    long long num = 0;
    for(long long i = 0; i < itc_len(s); i++){
        num += s[i] - 48;
        num *= 10;
    }
    num /= 10;
    return num;
}

float itc_toFloat(string s){
    float integer;
    string strInteger = "";
    float mantiss;
    string strMantiss = "";
    bool integerDone = false;
    int length = itc_len(s);
    for(int i = 0; i < length; i++){
        if(s[i] == '.'){
            integerDone = true;
            i++;
        }
        if(!integerDone){
            strInteger += s[i];
        }
        else
            strMantiss += s[i];

    }
    integer = (float)(itc_toInt(strInteger));
    mantiss = itc_toInt(strMantiss) / pow(10, itc_len(strMantiss));
    return integer + mantiss;
}

void itc_swap(int &a, int &b){
    int buffer = a;
    a = b;
    b = buffer;
}

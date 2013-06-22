/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: HoHcn
 * Section: myself
 * This file is the completed project for the Numeric Conversions problem.
 */

#include <iostream>
#include <string>
#include <simpio.h>
#include "console.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);
bool isInt(string str);

/* Main program */

int main() {
    string str0 = getLine("n=?");
    /*If the inputs are not valid, ask for inputs again*/
    while (!isInt(str0)){
        cout<<"Not a valid input. Enter again. "<<endl;
        str0 = getLine("n=?");
    }
    int n = stringToInt(str0);
    cout <<"string is: "<<intToString(n)<<endl;
    return 0;
}

string intToString(int n){
    string str;
    string minus = "-";
    if (n==0) str = "0";
    else if(n>0 && n<10) str = string()+ char(n+'0');
    else if(n>=10) str = intToString(n/10) += (intToString(n%10));
    else str = minus+=(intToString(-n));
    return str;
}

int stringToInt(string str){
    int n = atoi(str.c_str());
    return n;
}

bool isInt(string str){
    for (int i=0;i<str.length();i++){
        if (str[0]=='-') i++;
        if(!isdigit(str[i])){
            return false;
            break;
        }
    }
    return true;
}
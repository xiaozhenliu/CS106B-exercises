/*
 * File: Combinations.cpp
 * ----------------------
 * Name: HoHcn
 * Section: Myself
 * This file is the completed project for the Combinations problem.
 */

#include <iostream>
#include <string>
#include <simpio.h>
#include <cctype>
#include "console.h"
using namespace std;
bool isInt(string str); //test if the string is a positive integer
int combination(int n, int k); //combination results c(n,k)
int fact(int n); //factorial of n

int main() {
    int n;
    int k;
    
    /*Ask for input n, k */
    cout<<"Choose the combination parameters:"<<endl;
    string str1 = getLine("n=?");
    string str2 = getLine("k=?");
    
    /*If the inputs are not valid, ask for inputs again*/
    while ((str1<str2)||(!(isInt(str1)&&(isInt(str2))))){
        cout<<"Not a valid input. Enter again. "<<endl;
        str1 = getLine("n=?");
        str2 = getLine("k=?");
        }
    
    /*Calculate combination of n, k */
    n = atoi(str1.c_str());
    k = atoi(str2.c_str());
    cout<<"Inputs are correct. The combination result is: "<<combination(n,k)<<"."<<endl;
    return 0;
    }

/*This function examines whether an input string is a positive int*/
bool isInt(string str){
    for (int i=0;i<str.length();i++){
        if(!isdigit(str[i]))return false;
        break;
    }
    int n = atoi(str.c_str());
    if(n<=0) return false;
    else return true;
}

/*This function calculates the combination results of n and k*/
int combination(int n, int k){
    return (double) fact(n) / (fact(k) * fact(n-k));
}


/*This function calcuates the factorial of n*/
int fact(int n){
    int factN = 1;
    if (n!=0) {
        for (int i = 0; i < n; i++){
            factN = factN * (i+1);
            }
        }
    return factN;
}
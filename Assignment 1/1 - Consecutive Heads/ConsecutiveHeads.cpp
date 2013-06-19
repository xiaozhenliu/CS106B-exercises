/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: HoH
 * Section: Myself
 * This file is a completed project for the Consecutive Heads problem.
 */

#include <iostream>
#include <simpio.h>
#include <string>
#include "console.h"
using namespace std;
/*Find out number of flips needed to get a particular sequence*/

const int SAMPLESIZE = 10; //sample size
int sumN = 0; //initialize sum of numbers needed for all tests
double nflipAvg = 0; //initialize average of numbers needed for all tests
bool testSeq(string inputSeq);
string flipIt();
int flipCoin(string coinSeq);

int main(){
    string coinSeq;
    coinSeq = getLine("Please enter the sequence you want: ");
    /*test if the input string is consists of H and T only*/
    while (!testSeq(coinSeq)) {
        cout << "The input is incorrect. Please enter again, only combinations of T and H are allowed:"<<endl;
        coinSeq = getLine("Please enter the sequence you want: ");
    }
    cout << "Input correct. Calculating " <<coinSeq<<endl;
    /*Calculate average number of flips*/
    
    int nflip = 0;
    for (int i=0;i<10;i++){
        nflip = flipCoin(coinSeq); //flip the coin! get the numbers needed for one test
        cout << "number of flips this time is: "<<nflip<<endl;
        sumN = sumN + nflip;
    nflipAvg = double(sumN)/(i+1); //calculate average numbers from samples tested
    }
    cout << "It takes an average of "<<nflipAvg<<" flips to get the sequence "<<coinSeq<<"."<<endl;
    return 0;
}

bool testSeq(string inputSeq){
    for (int i=0;i<inputSeq.length();i++){
        if ((inputSeq.substr(i,1)!="H")&&(inputSeq.substr(i,1)!="T")){
            return false;
            break;
        }
    }
    return true;
}

string flipIt(){
  int oneFlip = rand()%2;
if (oneFlip==0) return "H";
   else return "T";
}

int flipCoin(string coinSeq){
    string flipRecord;
    string newFlip;
    int csl = coinSeq.length();
    for (int i = 0; i<csl;i++){
        newFlip = flipIt();
        flipRecord.append(newFlip);
    }
    int start = 0;
        while (flipRecord.substr(start)!=coinSeq) {
            newFlip = flipIt();
            flipRecord.append(newFlip);
            start++;
            }
    cout << flipRecord<<endl;
    return start+coinSeq.length();
    }
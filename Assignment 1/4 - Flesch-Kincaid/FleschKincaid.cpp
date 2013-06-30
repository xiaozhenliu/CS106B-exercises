/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: HoHcn
 * Section: myself
 * This file is the completed project for the Flesch-Kincaid problem.
 */

#include <iostream>
#include <fstream>
#include "simpio.h"
#include "console.h"
#include "tokenscanner.h"

using namespace std;

int words = 0; //number of words;
int syl = 0; //number of syllables;
int stc = 0; //number of sentences;
double gLevel = 0;//grade level value;
int countSyl(string token);
bool isVowel(char ch);

int main() {
    
    /*Ask for file name, see if the file exists*/
    ifstream infile;
    string fName = getLine("Enter file name: ");
    infile.open(fName.c_str());
    while(infile.fail()){
        cout << "File does not exit."<<endl;
        string fName = getLine("Enter file name: ");
        infile.open(fName.c_str());
    }
    
    /*Scan the token*/
    string token;
    TokenType type;
    TokenScanner scanner(infile);
    scanner.ignoreWhitespace();
    
    /*claim variables*/
    string previousToken;
    string nextToken;
    string nextToken2;
    TokenType previousType;
    TokenType nextType;
    
    token = scanner.nextToken(); //obtain the first token
    
    while (scanner.hasMoreTokens()){   //execute until no more token left
        previousToken = token;          //save current token for future use
        previousType = scanner.getTokenType(previousToken); //get current token type for future use
        
        token = scanner.nextToken();      //obtain the next token
        type = scanner.getTokenType(token);
        
        /*Scenario 1: words like "Charleston's" or quoted, like 'Friend'*/
        if ((previousType==WORD)&&(token == "'")){
            nextToken = scanner.nextToken();
            nextType = scanner.getTokenType(nextToken);
            nextToken2 = scanner.nextToken();
            if (nextToken2 == "'") {
                scanner.saveToken(token += nextToken += nextToken2);
                scanner.saveToken(previousToken);
            }
            else {
                scanner.saveToken(nextToken2);
                scanner.saveToken(previousToken+=token+=nextToken);
            }
        }
        
        /*Scenario 2: word has "-", like "A-1"*/
        else if ((previousType == WORD)&&((token =="-"))){   //
            nextToken = scanner.nextToken();
            scanner.saveToken(previousToken += token += nextToken);
        }
        
        /*Scenario 3: Single words*/
        
        else if ((previousToken!="\"")&&((previousType==WORD)||(previousType==STRING)||(previousType==NUMBER))){
                scanner.saveToken(token);
                token = previousToken;
                int iSyl = countSyl(token);     //calculate syllables in this word
                words++;                    //count as a word
            
                cout <<"Token: ["<<token<<"]"<<" ("<<words<<"word, "<<countSyl(token)<<" syllables.)";
                syl=syl+iSyl;               //count total number of syllables
        }
            /*Scenario 4: Punctuates and scentences*/
        else{
                scanner.saveToken(token);
                token = previousToken;
                cout <<"Token: ["<<token<<"]";
                if ((token == ".")||(token =="?")||(token=="!")){
                    cout <<"(End of a sentence)";
                    stc++;

                }
            }
        token= scanner.nextToken();

        cout<<endl;
    }
    if((token == ".")||(token =="?")||(token=="!")){
        cout <<"Token: ["<<token<<"]";
        cout <<"(End of a sentence and the file)"<<endl;
    }
    else cout <<"Token: ["<<token<<"]"<<endl;
    stc++;
    infile.close();
    
    /*Summary of Results*/
    cout <<"Words: "<<words<<endl;
    cout <<"Syllables: "<<syl<<endl;
    cout <<"Sentences: "<<stc<<endl;
    gLevel = -15.59+0.39*(double(words)/stc)+11.8*(double(syl)/words);
    cout <<"Grade Level: "<<gLevel<<endl;
    return 0;
}
int countSyl(string token){
    int iSyl =0;
    int L = token.length()-1;
    if(L==1) iSyl = 1;
    else {
        for (int i=0;i<L;i++){
            if((isVowel(token[i]))&&(!isVowel(token[i+1]))) iSyl++;
            else if ((isVowel(token[i]))&&(isVowel(token[i+1]))) {
                iSyl++;
                i++;
            }
        }
        if (token[L]=='e'&&(!isVowel(token[L-1])))iSyl--;
        if (iSyl<1) iSyl = 1;
    }
    return iSyl;
}
bool isVowel(char ch){
    if ((ch =='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')||(ch=='y')) return true;
    else return false;
}
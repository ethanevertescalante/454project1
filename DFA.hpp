//
// Created by Ethan Escalante on 10/11/25.
//

#include <vector>
#include <string>
#include "gmpxx.h"
using namespace std;

#ifndef CS454PROJECT1_DFA_HPP
#define CS454PROJECT1_DFA_HPP

#include <iostream>

class DFA{
public:
    DFA buildDfaL();
    DFA buildMp(DFA& L, int state, int symbolA);
    bool areAllFourCharsInSubString(vector<int>& subString);
    mpz_class countAcceptedStrings(DFA& dfa, int n);
    int& getNextState(DFA& dfa,int state, int symbol);
    int& getNextStateOfAA(DFA& M, int state, int symbolA);
    int getNumStates(){
        return numStates;
    }
    int getAccepting(int i){
        return accept[i];
    }
    mpz_class countEvenWithMiddleAA_fast(DFA& M, int n, int symbolA);


private:
    int numStates = 0;
    int sigma = 0; //the alphabet in the language
    int startState = 0;
    vector<int> accept; // 0 == reject, 1 == accept
    vector<int> transitions;





};


#endif //CS454PROJECT1_DFA_HPP

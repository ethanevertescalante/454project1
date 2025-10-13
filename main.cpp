#include <iostream>
#include "DFA.hpp"
#include "gmpxx.h"
using namespace std;

int main() {
    DFA dfaL;
    dfaL.buildDfaL();

    DFA dfaLDoublePrime;
    dfaLDoublePrime.buildDfaL();

    while(true){
        std::cout <<  "Choose from the selection of options:\n"
                      "1. Count number of strings of length n in language L\n"
                      "2. Count number of strings of length n in language L' with middle of \"aa\"\n"
                      "3. Quit\n"
                      "Enter Choice: ";

        int choice;
        cin >> choice;

        if(choice == 1 || choice == 2){
            int n;
            cout << "Number of States in L: " << dfaL.getNumStates() << "\n";
            cout << "Enter n from 1 to 300: ";
            cin >> n;
            if(n < 1 || n > 300){
                cout << "n is out of range, please choose a value between 1 and 300\n";
                continue;
            }

            if(choice == 1){
                mpz_class answer = dfaL.countAcceptedStrings(dfaL, n);
                cout << "\nUsing language \"L\" and with n = " << n << " there are " << answer << " strings w of length n that satisfy rule #1" << "\n\n";
            }else{
                //so we have to count the string in the form  < first + "aa" + second >

                //must be even and must contain "aa" string in the middle
                        //ex) acdbaaacdb where first = acdb, "aa", and second = acdb

                //we will have to count the string in pairs:
                        //ex) (a,c),(d,b) (a,a) (a,c),(d,b)

                cout << "\nunder construction...\n\n";
            }

        }else if(choice == 3){
            cout << "Exiting Execution...";
            break;
        }else{
            cout << "Invalid Choice. Please input a number from 1 to 3.";
        }
    }
    return 0;
}

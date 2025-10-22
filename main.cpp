//Martin Villasenor and Ethan Escalante

#include <iostream>
#include "DFA.hpp"
#include "gmpxx.h"
using namespace std;

int main() {
    cout << "Building DFA L...\n";
    DFA dfaL;
    dfaL = dfaL.buildDfaL();
    cout << "DFA L Built\n\n";
    cout << "Building DFA Mp...\n";
    DFA Mp;
    Mp = dfaL.buildMp(dfaL, dfaL.getNumStates(), 0);
    cout << "DFA Mp Build\n\n";

    cout << "DFA L Info:\n" <<
            "Num States: " << dfaL.getNumStates() << endl << endl;

    cout << "DFA Mp Info:\n" <<
            "Num States: " << Mp.getNumStates() << endl << endl;





//    TODO::DELETE
//    DFA dfaLDoublePrime;
//    dfaLDoublePrime.buildDfaL();


/*
 * TODO: The user is asked to enter an integer q, 0 <= q <= 1366^2 -1 and the input symbol j (as 0, 1, 2, 3 that represent a, b, c and d). It returns delta(q, j).
 */
    while(true){
        std::cout <<  "Choose from the selection of options:\n"
                      "1. Count number of strings of length n in language L\n"
                      "2. Count number of strings of length n in language L' with middle of \"aa\"\n"
                      "3. Output information about the delta function for the DFA of Problem 2\n"
                      "4. Quit\n"
                      "Enter Choice: ";

        int choice;
        cin >> choice;

        if(choice == 1 || choice == 2){


            if(choice == 1){

                cout << "Number of States in L: " << dfaL.getNumStates() << "\n";

                int n;
                cout << "Enter n from 1 to 300: ";
                cin >> n;
                mpz_class answer = dfaL.countAcceptedStrings(dfaL, n);
                cout << "\nUsing language \"L\" and with n = " << n << " there are " << answer << " strings w of length " << n << " that satisfy rule #1" << "\n\n";
            }else{
                //EXPLANATION
                //so we have to count the string in the form  < first + "aa" + second >
                //must be even and must contain "aa" string in the middle
                        //ex) acdbaaacdb where first = acdb, "aa", and second = acdb
                //we will have to count the string in pairs:
                        //ex) (a,c),(d,b) (a,a) (a,c),(d,b)

                int n;
                cout << "Enter n (even, ≥2): ";
                cin >> n;

                if (n % 2 != 0 || n < 2) {
                    cout << "n must be even and at least 2.\n";
                    continue;
                }

                int symbolA = 0; // encoding for 'a'
                mpz_class result = dfaL.countEvenWithMiddleAA_fast(dfaL, n, symbolA);

                cout << "\nUsing L'' (even length, middle 'aa'), n = " << n
                     << "\nNumber of strings = " << result.get_str() << "\n\n";
            }
        }else if(choice == 3){
            cout << "under construction...\n";
        }
        else if(choice == 4){
            cout << "Exiting Execution...";
            break;
        }else{
            cout << "Invalid Choice. Please input a number from 1 to 4.\n";
        }
    }
    return 0;
}

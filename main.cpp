#include <iostream>
#include "DFA.hpp"
#include "gmpxx.h"
using namespace std;

int main() {
    DFA dfa;
    while(true){
        std::cout <<  "Choose from the selection of options:\n"
                      "1. Count strings of length n in language L\n"
                      "2. Count string of length n in language L' with middle of \"aa\"\n"
                      "3. Quit\n"
                      "Enter Choice: ";

        int choice;
        cin >> choice;

        if(choice == 1){
            int n;
            cout << "Enter n from 1 to 300: ";
            cin >> n;
            if(n < 1 || n > 300){
                cout << "n is out of range, please choose a value between 1 and 300\n";
                continue;
            }
            mpz_class answer = dfa.countAcceptedStrings(dfa, n);
            cout << "\nUsing language \"L\" and with n = " << n << " there are " << answer << " strings w of length n that satisfy rule #1" << "\n\n";

        }else if(choice == 2){
            cout << "\nunder construction...\n\n";
        }else if(choice == 3){
            cout << "Exiting Execution...";
            break;
        }else{
            cout << "Invalid Choice. Please input a number from 1 to 3.";
        }
    }
    return 0;
}

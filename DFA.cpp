#include "DFA.hpp"
#include "Buffer.hpp"

int& DFA::getNextState(int state, int symbol){
    return transitions[state * sigma + symbol];
}

int& DFA::getNextStateOfAA(DFA &M, int state, int symbolA) {
    //go to the first 'a', then go to the subsequent 'a' ('aa')
    int stateA = M.getNextState(state, symbolA);
    return M.getNextState(stateA, symbolA);
}

bool DFA::areAllFourCharsInSubString(vector<int>& subString){
    vector<bool> seenChars(4, false);
    for(int i = 0; i < 6; i++) seenChars[subString[i]] = true;
    //todo:: look up a better way of returning all values that have been seen, this looks nasty
    //{0,1,2,3} correspond with {a,b,c,d}
    return seenChars[0] && seenChars[1] && seenChars[2] && seenChars[3];
}

void DFA::buildDfaL(){
    //this is the constructor, just in a separate method
    const int SIGMA = 4; //number of chars in the language

    BufferIndex bufferIndex = makeBufferIndex();
    sigma = SIGMA;
    numStates = bufferIndex.totalNumberStates + 1;
    startState = bufferIndex.offset[0];
    accept.assign(numStates,1); //https://en.cppreference.com/w/cpp/container/vector/assign.html
    accept[bufferIndex.failId] = 0;
    transitions.assign(numStates * SIGMA, bufferIndex.failId);

    for(int i = 0; i < 6; i++){
        int regionSize = (int)pow(4,i);
        for(int j = 0; j < regionSize; j++){
            int s = bufferIndex.offset[i] + j;
            if(s == bufferIndex.failId) continue;

            vector<int> buffer = decodeBase4(i,j);

            for(int k = 0; k  < SIGMA; k++){
                if(i < 5){ //append the next char until...(the else statement below)
                    vector<int> newBuffer = buffer;
                    newBuffer.push_back(k);
                    int j2 = encodeBase4(newBuffer);
                    int s2 = bufferIndex.offset[i+1] + j2;
                    getNextState(s,k) = s2;
                } else { // forming length 6 substring
                    vector<int> subString(6);
                    for (int l = 0; l < 5; ++l) subString[l] = buffer[l];
                    // append the new symbol as the 6th
                    subString[5] = k;

                    if (!areAllFourCharsInSubString(subString)) {
                        //fails forever and never comes back
                        getNextState(s, k) = bufferIndex.failId;
                    } else {
                        // rule check passes (all 4 chars are in the substring)
                        // keep last 5 symbols as the new buffer slides to next state
                        std::vector<int> newBuffer = { subString[1], subString[2], subString[3], subString[4], subString[5] };
                        int j2 = encodeBase4(newBuffer);
                        int s2 = bufferIndex.offset[5] + j2;
                        getNextState(s, k) = s2;
                    }
                }

            }

        }
    }
}


mpz_class DFA::countAcceptedStrings(DFA& dfa, int n){
    if(n < 0) return 0; //just in case (even though the input on main is also protected)

    vector<mpz_class> prev(dfa.numStates), next(dfa.numStates);
    for(int i = 0; i < dfa.numStates; i++){
        prev[i] = dfa.accept[i] ? 1 : 0;
    }

    for (int j = 1; j <= n; j++) { //for strings of length j
        fill(next.begin(), next.end(), 0); //https://en.cppreference.com/w/cpp/algorithm/fill.html
        for (int k = 0; k < dfa.numStates; k++) {
            mpz_class sum = 0;
            for (int l = 0; l < dfa.sigma; l++) {
                int t = dfa.getNextState(j, l);
                sum += prev[t];
            }
            next[k] = sum;
        }
        prev.swap(next); //swapping data to compute the next --> next values so that we don't reuse the same data for every computation
    }
    return prev[dfa.startState];

}


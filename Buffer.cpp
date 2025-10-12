#include "Buffer.hpp"
#include <cmath>
using namespace std;


BufferIndex makeBufferIndex(){
    BufferIndex bufferIndex;
    int current = 0;
    for(int i = 0; i < 6; i++){
        bufferIndex.offset.at(i) = current;
        current += (int)pow(4,i); //typecast to int from double
    }
    bufferIndex.totalNumberStates= current;
    bufferIndex.failId = bufferIndex.totalNumberStates;
    return bufferIndex;
}

int encodeBase4(vector<int>& digits){
    int value = 0;
    for(int d: digits) value = value * 4 + d;
    return value;
}

vector<int> decodeBase4(int length, int value){
    vector<int> out(length, 0);
    for(int i = length - 1; i > -1; i--){
        //similar if you were going to decode binary (base-2)
        //get the remainder of the value and that is your number
        //then assign into the out vector and return
        out[i] = value % 4;
        value /= 4;
    }

    return out;
}
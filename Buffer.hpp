//
// Created by Ethan Escalante on 10/11/25.
//

#include <vector>
using  namespace std;

#ifndef CS454PROJECT1_BUFFER_HPP
#define CS454PROJECT1_BUFFER_HPP

struct BufferIndex {
    vector<int> offset = vector<int>(6);
    int totalNumberStates = 0;
    int failId = -1;

};

BufferIndex makeBufferIndex();
int encodeBase4(vector<int>& digits);
std::vector<int> decodeBase4(int length, int value);

#endif //CS454PROJECT1_BUFFER_HPP

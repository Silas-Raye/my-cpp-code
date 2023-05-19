#include <iostream>
#include <string>
using namespace std;

int suffixCount(string S, int L) {
    string suffix = S.substr(S.size() - L, S.size());
    int count = 0;
    int nPos = S.find(suffix, 0);
    while (nPos != string::npos) {
        count++;
        nPos = S.find(suffix, nPos + 1); // If the suffix is not found, the find function will return string::npos
    }
    return count;
}
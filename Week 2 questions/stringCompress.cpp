#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int writeIdx = 0; 
        int count = 1;   

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && chars[i] == chars[i + 1]) {
                count++;
            } else {
                chars[writeIdx++] = chars[i];
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[writeIdx++] = c;
                    }
                }
                count = 1;
            }
        }
        return writeIdx;
    }
};
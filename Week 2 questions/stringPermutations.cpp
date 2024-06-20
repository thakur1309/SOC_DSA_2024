#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> uniquePerms;
    
    void backtrack(string& sortedS, string& current, vector<bool>& used, int n) {
        if (current.size() == n) {
            uniquePerms.push_back(current);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (used[i] || (i > 0 && sortedS[i] == sortedS[i-1] && !used[i-1])) {
                continue;
            }
            
            used[i] = true;
            current.push_back(sortedS[i]);
            backtrack(sortedS, current, used, n);
            current.pop_back();
            used[i] = false;
        }
    }
    
    vector<string> unique_permutations(string S) {
        sort(S.begin(), S.end());
        int n = S.size();
        vector<bool> used(n, false);
        
        string current;
        backtrack(S, current, used, n);
        
        return uniquePerms;
    }
};
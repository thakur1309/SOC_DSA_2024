#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        vector<int> sol;
        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.find(nums[i]) != hashMap.end()) {
                sol.push_back(nums[i]);
            } else {
                hashMap[nums[i]] = 1;
            }
        }
        return sol;
    }
};  
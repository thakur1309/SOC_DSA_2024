#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int break_flag = 0;
    int i, j;
    for (i = 0; i<nums.size()-1; i++) {
        for (j = i+1; j<nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                break_flag = 1;
                break;
            }
        }
        if (break_flag) break;
    }
    vector<int> sol;
    sol.push_back(i);
    sol.push_back(j);
    return sol;
}

vector<int> twoSumMap(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; //maps number to index
    vector<int> sol;
    for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if (num_map.count(comp)) {
            auto id = num_map.find(comp);
            sol.push_back(i);
            sol.push_back((*id).second);
            break;
        }
        else {
            num_map[nums[i]] = i;
        }
    }
    return sol;

}

int main() {
    vector<int> nums = {3, 3, 1};
    int target = 6;
    vector<int> sol = twoSumMap(nums, target);
    for (int i:sol) {
        cout<<i<<" ";
    }cout<<endl;
}
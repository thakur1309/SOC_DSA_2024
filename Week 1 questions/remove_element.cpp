#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) {
        return 0;
    }
    int i = 0;
    int j = 0;
    int n = nums.size();
    while (i < n && j < n) {
        if (nums[i] != val) {
            i++;
            continue;
        }        
        else {
            i--;
            j = i + 1;
            while (j < n) {
                if (nums[j] != val) {
                    nums[++i] = nums[j++];
                }
                else {
                    j++;
                    continue;
                }

            }
        }
    }
    return min(i+1, n);
}

int main() {
    vector<int> nums = {2};
    int k = removeElement(nums, 3);
    for (auto i:nums) {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"k->"<<k<<endl;
}
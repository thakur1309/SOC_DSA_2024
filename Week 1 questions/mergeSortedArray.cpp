#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto i = nums1.begin();
        auto j = nums2.begin();
        int m_copy = m;
        while(j != nums2.end()) {
            while(i != nums1.end() && (*i) < (*j) && (i-nums1.begin()<m)) {
                i++;
            }
            i = nums1.insert(i, (*j));
            i++;
            j++;
            m++;
        }
         while (nums1.size() > m_copy + n) {
            nums1.pop_back();
        }
};};
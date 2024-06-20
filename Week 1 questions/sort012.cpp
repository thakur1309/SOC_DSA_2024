#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    //   Write your code here
    int l = 0;
    int r = n-1;
    int curr = 0;
    while (curr <= r) {
        if (arr[curr] == 1) curr++;
        else if (arr[curr] == 0) {
            swap(arr[curr++], arr[l++]);
        }
        else swap(arr[curr], arr[r--]);
    }
}
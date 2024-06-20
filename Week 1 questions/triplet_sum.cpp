#include <bits/stdc++.h>
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(), arr.end());
    vector<vector<int>> sol;
    
    for (int i = 0; i < n-2; i++) {
        if (i > 0 && (arr[i] == arr[i-1])) continue; //duplicate for first element
        int l = i + 1;
        int h = n - 1;
        while (l < h) {
            int sum = arr[i] + arr[l] + arr[h];
            if (sum == K) {
                sol.push_back({arr[i], arr[l], arr[h]});
                while((l<h) && (arr[l] == arr[l+1])) l++;
                while((l<h) && (arr[h] == arr[h-1])) h--;
                l++;
                h--;
            }
            else if (sum < K) {
                l++;
            }
            else h--;
        }
    }
    if (sol.size() == 0) {
        cout<<-1;
    }
    return sol;
}

int main () {
    int N, n, k;
    cout<<"Enter input: ";
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>n;
        vector<int> arr;
        for (int j = 0; j < n; j++) {
            int curr_val;
            cin>>curr_val;
            arr.push_back(curr_val);
        }
        cin>>k;
        vector<vector<int>> sol = findTriplets(arr, n, k);
        for (auto i:sol) {
            for (int j:i) {
                cout<<j<<" ";
            }cout<<"; ";
        }cout<<endl;
    }
}
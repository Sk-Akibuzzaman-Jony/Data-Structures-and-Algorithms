// https://www.codingninjas.com/studio/problems/verify-preorder-sequence-in-binary-search-tree_1281309?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void solve(int& idx, vector<int>& arr, int min, int max){
    if(idx == arr.size()){
        return;
    }

    if(arr[idx] < max && arr[idx] > min){
        int a = arr[idx++];
        solve(idx, arr, min, a);
        solve(idx, arr, a, max);
    } else {
        return;
    }
}

bool isBSTPreorder(vector<int> &arr) 
{
    int min = INT_MIN, max = INT_MAX;
    int idx = 0;
    solve(idx, arr, min, max);
    if(idx == arr.size())
        return true;
    return false;
}

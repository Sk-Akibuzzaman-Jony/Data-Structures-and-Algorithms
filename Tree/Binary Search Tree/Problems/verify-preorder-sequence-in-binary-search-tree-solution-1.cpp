// https://www.codingninjas.com/studio/problems/verify-preorder-sequence-in-binary-search-tree_1281309?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

int findPos(vector<int> arr, int s, int e, int target){
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] > target){
            e = mid-1;
        }
        if(arr[mid] < target){
            s = mid+1;
        }
    }
    return -1;
    
}

bool solve(vector<int> &arr, int sIn, int eIn, int& sPre, vector<int>& inorder){
    if(eIn-sIn < 0){
        return true;
    }

    int pos = findPos(inorder, sIn, eIn, arr[sPre]);
    sPre++;
    if(pos != -1){
        bool leftAns = solve(arr, sIn, pos-1, sPre, inorder);
        bool rightAns = solve(arr, pos+1, eIn, sPre, inorder);
        return leftAns && rightAns;
    } else {
        return false;
    }

}

bool isBSTPreorder(vector<int> &arr) 
{   
    vector<int> inorder = arr;
    sort(inorder.begin(), inorder.end());
    int sPre = 0;
    return solve(arr, 0, inorder.size()-1, sPre, inorder);
}

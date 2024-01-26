// https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258

#include <bits/stdc++.h>

int subarraysWithSumK(vector < int > a, int b) {
    unordered_map<int, int> mp;
    int count = 0;
    int xr = 0;
    mp[0] = 0;
    for(auto x : a){
        xr = xr ^ x;
        if(xr == b) count++;
        if(mp.find(xr^b) != mp.end()){
            count += mp[xr^b];
        }
        mp[xr]++;
    }
    return count;
}

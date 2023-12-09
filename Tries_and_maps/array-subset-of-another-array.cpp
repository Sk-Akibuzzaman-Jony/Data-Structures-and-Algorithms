// https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

string isSubset(int a1[], int a2[], int n, int m) {
    //creating a freq map for a1
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[a1[i]]++;
    }
    
    //comparing it with a2
    for(int i = 0; i < m; i++){
        if(mp.find(a2[i]) != mp.end() && mp[a2[i]] > 0){
            mp[a2[i]]--;
        } else {
            return "No";
        }
    }
    return "Yes";
}

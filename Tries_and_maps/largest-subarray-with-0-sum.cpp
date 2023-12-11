// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int, int> mp;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                ans = max(ans, i+1);
            }
            else if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            else {
                ans = max(ans, i - mp[sum]);
            }
        }
        return ans;
    }
};

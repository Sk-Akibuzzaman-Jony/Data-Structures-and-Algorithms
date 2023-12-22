// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

class Solution{
    public:
    long long mod = 1e9+7;
    //normal recursion
    long long solveRec(int n, int k){
        if(n == 1){
            return k%mod;
        }
        if(n == 2){
            return (k + k*(k-1))%mod;
        }
        
        return ((solveRec(n-2,k)+solveRec(n-1,k))*(k-1)) % mod;
    }
    
    //recursion + memoization
    long long solveMem(int n, int k, vector<long long>& dp){
        if(n == 1){
            return k%mod;
        }
        if(n == 2){
            return ((k%mod)*(k%mod))%mod;
        }
        if(dp[n] != -1){
            return dp[n] % mod;
        }
        
        return dp[n] = ((solveMem(n - 2, k, dp) + solveMem(n - 1, k, dp)) % mod * (k - 1)%mod) % mod;
    }
    
    // bottom-up (tabular) method
    long long solveTab(int n, int k){
        vector<long long> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = k % mod;
        dp[2] = ((k%mod)*(k%mod))%mod;
        
        for(long long i = 3; i <= n; i++){
            dp[i]= (((dp[i- 1]+ dp[i- 2])%mod)*(k- 1)%mod)%mod;
        }
        
        return dp[n];
        
    }

    // space-optimized    
    long long solveSO(int n, int k){
        long long prev2 = k%mod;
        if(n == 1) return prev2;
        long long prev1 = ((k%mod)*(k%mod))%mod;
        if(n == 2) return prev1;
        long long curr;
        for(long long i = 3; i <= n; i++){
             curr = (((prev1 + prev2)%mod)*(k-1) % mod)%mod;
             
             prev2 = prev1;
             prev1 = curr;
        }
        return curr;
    }
    
    long long countWays(int n, int k){
         vector<long long> dp(n+1, -1);
         return solveSO(n, k);
        
    }
};

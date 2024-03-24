// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        for(int len = 2; len <= N; len++){
            int col = len;
            for(int row = 0; row < N-len; row++){
                dp[row][col] = INT_MAX;
                for(int k = row+1; k < col; k++){
                    dp[row][col] = min(dp[row][col], 
                    dp[row][k]+dp[k][col]+arr[row]*arr[k]*arr[col]);
                }
                col++;
            }
        }
        return dp[0][N-1];
    }
};

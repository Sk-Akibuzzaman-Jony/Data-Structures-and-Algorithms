// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

int solve(vector<int> wt, vector<int> val, int n, int i, int W, vector<vector<int>>& dp){
	if(i == n){
		return 0;
	}
	
	if(dp[i][W] != -1) return dp[i][W];
	int include = INT_MIN;
	if (wt[i] <= W){
		include = val[i] + solve(wt, val, n, i+1, W-wt[i], dp);
	}
	int exclude = solve(wt, val, n, i+1, W, dp);
	
	return dp[i][W] = max(include, exclude);
}

// bottom-up (tabulation method)
int solveTab(vector<int> wt, vector<int> val, int W, int n){

	vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j <= W; j++){
			int include = INT_MIN;
			if (wt[i] <= j){
				include = val[i] + dp[i+1][j-wt[i]];
			}
			int exclude = dp[i+1][j];
			
			dp[i][j] = max(include, exclude);
		}
	}
	return dp[0][W];
}
    
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
	return solveTab(weight, value, maxWeight, n);
}

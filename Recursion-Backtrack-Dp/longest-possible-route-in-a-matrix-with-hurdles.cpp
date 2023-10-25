// https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1

class Solution {
public:
    int movex[4] = {0, 1, 0, -1};
    int movey[4] = {1, 0, -1, 0};
                // right, down, left, up
                
    bool isSafe(vector<vector<int>>& matrix, vector<vector<bool>> visited, int xs, int ys){
        return xs >= 0 && ys >= 0 && ys < matrix[0].size() && xs < matrix.size() && !visited[xs][ys] && matrix[xs][ys];
    }
    
    void solve(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int xs, int ys, int xd, int yd, int& ans,int curr){
        if(xs == xd && ys == yd){
            ans = max(ans, curr);
            return;
        }

 
        for(int i = 0; i < 4; i++){
            if(isSafe(matrix, visited, xs+movex[i], ys+movey[i])){
                visited[xs+movex[i]][ys+movey[i]] = true;
                solve(matrix, visited, xs+movex[i], ys+movey[i], xd, yd, ans, curr+1);
                visited[xs+movex[i]][ys+movey[i]] = false;

            }
        }

    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[xs][ys] == 0 || matrix[xd][yd] == 0) return -1;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[xs][ys] = true;
        int ans = -1;
        solve(matrix, visited, xs, ys, xd, yd, ans, 0);
        return ans;
    }
};

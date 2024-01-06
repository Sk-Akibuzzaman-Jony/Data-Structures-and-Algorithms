// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
            return 0; // Knight is already at the target position
        }
        
	    //implementing BFS
	    queue<pair<pair<int, int>,int>> q; // x, y, steps
	    vector<vector<bool>> visited(N, vector<bool>(N, false));
	    vector<vector<int>> dirs = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
	    int count = 0;
	    q.push({{KnightPos[0]-1, KnightPos[1]-1}, count});
	    
	    while(!q.empty()){
	        auto fNode = q.front();q.pop();
	        
	        if(fNode.first.first == TargetPos[0]-1 && fNode.first.second == TargetPos[1]-1){
	            return fNode.second;
	        }
	        
	        for(int i = 0; i < 8; i++){
	            int newx = fNode.first.first+dirs[i][0];
	            int newy = fNode.first.second+dirs[i][1];
	            if(newx >= 0 && newy >= 0 && newx < N && newy < N  && !visited[newx][newy]){
	                q.push({{newx, newy}, fNode.second+1});\
	                visited[newx][newy] = true;
	            }
	        }
	    }
	    return 0;
	    
	}
};

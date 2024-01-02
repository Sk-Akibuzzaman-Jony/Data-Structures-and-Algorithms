// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    // in places where we have no edges (-1) we are putting a large number
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e9;
	        }
	    }
	    
	    // floyd warshall algo
	    for(int helper = 0; helper < n; helper++){
	        for(int src = 0; src < n; src++){
	            for(int dest = 0; dest < n; dest++){
	                matrix[src][dest] = min(matrix[src][dest], matrix[src][helper]+matrix[helper][dest]);
	            }
	        }
	    }
	    
	    // resetting all the 1e9 number to -1
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	        }
	    }
	}
};

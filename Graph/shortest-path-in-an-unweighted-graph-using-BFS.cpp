// https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=PROBLEM

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//making a adjacecy matrix
	vector<vector<int>> adj(n+1);
	for(auto x : edges){
		int parent = x.first;
		int nbr = x.second;
		adj[parent].push_back(nbr);
		adj[nbr].push_back(parent);
	}
	vector<int> visited(n+1, false);
	vector<int> parent(n+1);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int firstNode = q.front(); q.pop();
		for(auto nbr : adj[firstNode]){
			if(!visited[nbr]){
				visited[nbr] = true;
				parent[nbr] = firstNode;
				q.push(nbr);
			}
		}
	}

	vector<int> ans;
	while(t != -1){
		ans.push_back(t);
		t = parent[t];
	}

	reverse(ans.begin(), ans.end());
	return ans;
		
}

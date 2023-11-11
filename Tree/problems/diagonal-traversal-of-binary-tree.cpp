// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1


void solve(Node* root, map<int, vector<int>>& mp, int level){
    if(root == NULL){
        return;
    }
    
    if(mp.find(level) == mp.end()){
        vector<int> temp;
        temp.push_back(root->data);
        mp[level] = temp;
    } else {
        mp[level].push_back(root->data);
    }
    
    solve(root->left, mp, level+1);
    solve(root->right, mp, level);
}


vector<int> diagonal(Node *root){
   map<int, vector<int>> mp;
   solve(root, mp, 0);
   
   vector<int> ans;
   for(auto x : mp){
        for(auto y : x.second){
            ans.push_back(y);
        }
   }
   return ans;
}

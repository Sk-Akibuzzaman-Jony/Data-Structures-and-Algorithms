// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        //making a map that is going to store the horizontal distance
        //and the respective node
        map<int, Node*> mp;
        
        //performing level order traversal
        queue<pair<int, Node*>> q;
        q.push({0, root});
        while(!q.empty()){
            pair<int, Node*> temp = q.front();
            q.pop();
            
            Node* node = temp.second;
            int hd = temp.first;
            
            mp[hd] = node;
            
            if(node->left != NULL){
                q.push({hd-1, node->left});
            }
            
            if(node->right != NULL){
                q.push({hd+1, node->right});
            }
        }
        
        //now the answers are present in the map 
        vector<int> ans;
        for(auto x : mp){
            ans.push_back(x.second->data);
        }
        
        return ans;
    }
};

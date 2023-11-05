// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/0
// https://www.hackerrank.com/challenges/tree-top-view/problem

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        
        //creating a ordered map to store node and its horizontal distance
        map<int, Node*> mp;
        
        //making a queue for doing level order traversal and sotoring the horizontal 
        //distance in it too along with the node
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            
            Node* element = p.first;
            int hd = p.second;
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = element;
            }
            
            if(element->left != NULL){
                q.push({element->left, hd-1});
            }
            if(element->right != NULL){
                q.push({element->right, hd+1});
            }
        }
        
        
        // now the answer is present in mp 
        vector<int> ans;
        for(auto x : mp){
            ans.push_back(x.second->data);
        }
        
        return ans;
        
    }

};

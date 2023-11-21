// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Solution {
  public:
    
    pair<bool, pair<int, int>> solve(struct Node* root){
        if(root == NULL){
            return {true, {INT_MIN, 0}};
        }
        
        if(!root->left && !root->right){
            return {true, {root->data, 1}};
        }
        
        pair<bool, pair<int, int>> leftAns = solve(root->left);
        pair<bool, pair<int, int>> rightAns = solve(root->right);
        int nodeDiff = rightAns.second.second - leftAns.second.second;
        
        if(leftAns.first == true && rightAns.first == true && rightAns.second.first < root->data && leftAns.second.first < root->data
            && nodeDiff <= 0 && nodeDiff > -2 )
        {
            return {true, {root->data, rightAns.second.second + leftAns.second.second + 1}};
        } else {
            return {false, {-1, -1}};
        }
    }
    
    bool isHeap(struct Node* tree) {
        pair<bool, pair<int, int>> ans = solve(tree);
        return ans.first;
    }
};

// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> solve(Node* root){
        if(root == NULL){
            return {0, 0};
        }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        //including a node
        int a = root->data + left.second + right.second;
        
        //not including a node
        int b = max(left.first, left.second) + max(right.first, right.second);
        
        return {a,b};
        
    }
    int getMaxSum(Node *root) 
    {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};

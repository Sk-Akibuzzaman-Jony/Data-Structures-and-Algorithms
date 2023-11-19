// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1


class Solution{
  public:

    bool solve(Node* root, int min, int max){
        if(root == NULL){
            return false;
        }
        if(max-min <= 2){
            return true;
        }
        
        if(root->data > min && root->data < max){
            int a = root->data;
            bool leftAns = solve(root->left, min, a);
            bool rightAns = solve(root->right, a, max);
            return leftAns || rightAns;
        }
    }  

    bool isDeadEnd(Node *root)
    {
        return solve(root, 0, INT_MAX);
    }
};

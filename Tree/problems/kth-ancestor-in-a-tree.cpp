// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

bool solve(Node* root, int& k, int node, int& ans){
    if(root == NULL){
        return false;
    }
    
    if(root->data == node){
        return true;
    }
    
    bool leftAns = solve(root->left, k, node, ans);
    bool rightAns = solve(root->right, k, node, ans);
    
    if(leftAns || rightAns){
        k--;
        if(k == 0){
            ans = root->data;
        }
        return true;
    } else {
        return false;
    }
    
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}

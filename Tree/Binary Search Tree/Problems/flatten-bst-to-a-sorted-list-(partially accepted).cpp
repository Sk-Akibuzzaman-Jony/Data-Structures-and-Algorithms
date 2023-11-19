// https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTabValue=PROBLEM

void inorder(TreeNode<int>* root, TreeNode<int>*& prev){
    if(root==NULL){
        return;
    }
    inorder(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inorder(root->right, prev);
}
TreeNode<int>* flatten(TreeNode<int>*& root)
{
    TreeNode<int>* dummy = new TreeNode<int>(-1);
    TreeNode<int>* prev = dummy;
    inorder(root, prev);
    prev->right = prev->left = NULL;
    return dummy->right;

}

// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void solve(Node* root, Node* &head){
        if(root == NULL){
            return;
        }
        
        solve(root->right, head);
        
        root->right = head;
        
        if(head != NULL){
            head->left = root;
        }
        
        head = root;
        
        solve(root->left, head);
    }
    
    Node * bToDLL(Node *root)
    {
        
        Node* head = NULL;
        solve(root, head);
        return head;
        
    }
};

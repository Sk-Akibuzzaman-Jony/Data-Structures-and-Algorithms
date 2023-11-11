// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:
    vector<int> ans;
    
    void printLeft(Node* root){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            printLeft(root->left);
        } else {
            printLeft(root->right);
        }
    }
    
    void printRight(Node* root){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        
        if(root->right){
            printRight(root->right);
        } else {
            printRight(root->left);
        }
        
        ans.push_back(root->data);
    }
    
    void printLeaf(Node* root){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        printLeaf(root->left);
        printLeaf(root->right);
    }
    
    
    vector <int> boundary(Node *root)
    {
        ans.push_back(root->data);
        
        if(root->left || root->right){
            //print left nodes
            printLeft(root->left);
            
            //print leaf nodes;
            printLeaf(root);
            
            //print right nodes in reverse
            printRight(root->right);
        }
        
        return ans;
    };
};

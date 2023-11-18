// https://practice.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;

    }
};
class Solution{
    public:
    Node* insertIntoBST(int val, Node* &root){
        if(root == NULL){
            return new Node(val);
        }
        if(val > root->data){
            root->right = insertIntoBST(val, root->right);
        }
        if(val <= root->data){
            root->left = insertIntoBST(val, root->left);
        }
        return root;
    }
    
    
    int inorderSuc(int key, Node* &root){
        int suc = -1;
        Node* targetNode = root;

        while(targetNode && targetNode->data != key){
            if(key < targetNode->data){
                suc = targetNode->data;
                targetNode = targetNode->left;
            }
            else{
                targetNode = targetNode->right;
            }
        }
        
        if(targetNode){
            targetNode = targetNode->right;
            while(targetNode && targetNode->left){
                targetNode = targetNode->left;
            }
            suc = (targetNode ? targetNode->data : suc);
        }
        return suc;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = NULL;
        vector<int> ans(n, INT_MIN);
        for(int i = n-1; i >= 0; i--){
            root = insertIntoBST(arr[i], root);
            ans[i] = inorderSuc(arr[i], root);
        }

        return ans;
    }
};

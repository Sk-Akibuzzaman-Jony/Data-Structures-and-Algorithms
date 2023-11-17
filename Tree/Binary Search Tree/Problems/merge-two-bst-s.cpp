// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    void getInorder(Node* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }
        
        getInorder(root->left, inorder);
        inorder.push_back(root->data);
        getInorder(root->right, inorder);
        
    }
    
    vector<int> mergeArr(vector<int> arr1, vector<int> arr2){
        vector<int> ans;
        int i = 0, j = 0;
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i++]);
            } else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i < arr1.size()){
            ans.push_back(arr1[i++]);
        }
        while(j < arr2.size()){
            ans.push_back(arr2[j++]);
        }
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> inorder1;
       getInorder(root1, inorder1);
       
       vector<int> inorder2;
       getInorder(root2, inorder2);
       
       vector<int> inorder = mergeArr(inorder1, inorder2);
       return inorder;
       
    }
};

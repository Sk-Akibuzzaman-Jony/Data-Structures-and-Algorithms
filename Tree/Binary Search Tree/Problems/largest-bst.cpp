// https://practice.geeksforgeeks.org/problems/largest-bst/1

class NodeData{
    public:
    int size;
    int maxVal;
    int minVal;
    bool isValid;
    
    NodeData(){
        
    }
    
    NodeData(int size, int maxVal, int minVal, bool isValid){
        this->size = size;
        this->maxVal = maxVal;
        this->minVal = minVal;
        this->isValid = isValid;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeData solve(Node* root, int& ans){
        if(root == NULL){
            NodeData temp(0, INT_MIN, INT_MAX, true);
            return temp;
        }
        
        NodeData leftAns = solve(root->left, ans);
        NodeData rightAns = solve(root->right, ans);
        
        NodeData currAns;
        currAns.size = leftAns.size + rightAns.size + 1;
        currAns.maxVal = max(root->data, max(rightAns.maxVal, leftAns.maxVal));
        currAns.minVal = min(root->data, min(rightAns.minVal, leftAns.minVal));
        
        if(leftAns.isValid && rightAns.isValid && root->data < rightAns.minVal && root->data > leftAns.maxVal){
            currAns.isValid = true;
        } else {
            currAns.isValid = false;
        }
        
        if(currAns.isValid){
            ans = max(ans, currAns.size);
        }
        
        return currAns;
        
    }
    int largestBst(Node *root)
    {
    	int ans = 0;
    	solve(root, ans);
    	return ans;
    }
};

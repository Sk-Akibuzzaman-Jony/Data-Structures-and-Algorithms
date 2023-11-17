// https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1, suc = -1;

    TreeNode* targetNode = root;

    while(targetNode && targetNode->data != key){
        if(key < targetNode->data){
            suc = targetNode->data;
            targetNode = targetNode->left;
        }
        else{
            pred = targetNode->data;
            targetNode = targetNode->right;
        }
    }

    TreeNode* temp = targetNode;
    if(temp){
        temp = temp->left;
        while(temp && temp->right){
            temp = temp->right;
        }
        pred = (temp ? temp->data : pred);
    }
    temp = targetNode;
    if(temp){
        temp = temp->right;
        while(temp && temp->left){
            temp = temp->left;
        }
        suc = (temp ? temp->data : suc);
    }

    return {pred, suc};
}

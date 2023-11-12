// https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution {
  public:
    Node* findTargetAndCreateMap(Node* root, int target, unordered_map<Node*, Node*>& parent){
        //using level order traversal to do both the task
        queue<Node*> q;
        q.push(root);
        parent[root] = NULL;
        Node* targetNode = NULL;
        while(!q.empty()){
            Node* f = q.front();q.pop();
            if(f->data == target){
                targetNode = f;
            }
            if(f->left){
                q.push(f->left);
                parent[f->left] = f;
            }
            if(f->right){
                q.push(f->right);
                parent[f->right] = f;
            }
        }
        return targetNode;   
    }
    
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parent){
        queue<Node*> q; // this will hold the tree that are curr. burning
        int T = 0;
        q.push(targetNode);
        unordered_map<Node*, bool> isBurnt;
        isBurnt[targetNode] = true;
        while(!q.empty()){
            bool isBurning = false;
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* f = q.front(); q.pop();
                if(f->left && !isBurnt[f->left]){
                    q.push(f->left);
                    isBurning = true;
                    isBurnt[f->left] = true;
                }
                if(f->right && !isBurnt[f->right]){
                    q.push(f->right);
                    isBurning = true;
                    isBurnt[f->right] = true;
                }
                if(parent[f] && !isBurnt[parent[f]]){
                    q.push(parent[f]);
                    isBurning = true;
                    isBurnt[parent[f]] = true;
                }
            }
            if(isBurning){
                ++T;
            }
        }
        return T;
    }
    
    int minTime(Node* root, int target) 
    {
        // find the target node as well as make a node-parent map
        unordered_map<Node*, Node*> parent;
        Node* targetNode = findTargetAndCreateMap(root, target, parent);
        int t = burnTree(targetNode, parent);
        return t;
    }
};

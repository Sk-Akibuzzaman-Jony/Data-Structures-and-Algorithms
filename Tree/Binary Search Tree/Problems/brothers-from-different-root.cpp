// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans = 0;
        stack<Node*> sa, sb;
        Node* a = root1;
        Node* b = root2;
        while(1){
            while(a){
                sa.push(a);
                a = a->left;
            }
            while(b){
                sb.push(b);
                b = b->right;
            }
            if(sa.empty() || sb.empty()){
                //if any one the stack is empty 
                //we cannot obtain any further pairs
                break;
            }
            Node* atop = sa.top();
            Node* btop = sb.top();
            
            int sum = atop->data + btop->data;
            
            if(sum == x){
                ans++;
                sa.pop();
                a = atop->right;
                sb.pop();
                b = btop->left;
            }
            else if(sum < x){
                sa.pop();
                a = atop->right;
            }
            else {
                sb.pop();
                b = btop->left;
            }
        }
        return ans;
    }
};

//solving using hashmap
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        map<int, Node*> mp; // this will store the nodes and their address
        Node* temp = head1;
        while(temp != NULL){
            mp[temp->data] = temp;
            temp = temp->next;
        }
        
        temp = head2;
        while(temp != NULL){
            mp[temp->data] = temp;
            temp = temp->next;
        }
        
        Node* ans = new Node(-1);
        temp = ans;
        for(auto x : mp){
            temp->next = x.second;
            temp = temp->next;
        }
        temp->next = NULL; // made mistake here
        return ans->next;
    }
};

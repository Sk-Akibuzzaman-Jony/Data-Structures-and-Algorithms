//https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class info{
    public:
    int data;
    int row;
    int col;
    
    info(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class cmp{
    public:
    bool operator()(info* i1, info* i2){
        return i1->data > i2->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<info*, vector<info*>, cmp> q;
        vector<int> ans;
        for(int i = 0; i < K; i++){
            info* temp = new info(arr[i][0], i, 0);
            q.push(temp);
        }
        
        while(!q.empty()){
            info* t = q.top();q.pop();
            ans.push_back(t->data);
            if((t->col)+1 < K){
                info* newInfo = new info(arr[t->row][(t->col)+1], t->row, (t->col)+1);
                q.push(newInfo);
            }
        }
        
        return ans;
    }
};

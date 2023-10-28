// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Function to reverse first k elements of a queue.

void solve(queue<int>& q, int totalSize, int k){
    //base case
    if(q.size() == totalSize-k){
        return;
    }
    
    int f = q.front();
    q.pop();
    
    solve(q, totalSize, k);
    
    q.push(f);
}

queue<int> modifyQueue(queue<int> q, int k) {
    solve(q, q.size(), k);
    int n = q.size()-k;
    
    while(n--){
        q.push(q.front());
        q.pop();
    }
    
    return q;
}

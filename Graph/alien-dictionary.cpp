// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        vector<int> inDegree(K, 0);
        for(int i = 1; i < N; i++){
            string word1 = dict[i-1];
            string word2 = dict[i];
            for(int j = 0; j < min(word1.length(), word2.length()); j++){
                if(word1[j] != word2[j]){
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    inDegree[word2[j]-'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i = 0; i < K; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int fNode = q.front(); q.pop();
            ans += (char)(fNode+'a');
            for(int nbr : adj[fNode]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};

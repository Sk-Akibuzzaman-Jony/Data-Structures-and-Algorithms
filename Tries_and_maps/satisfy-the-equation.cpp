// https://www.geeksforgeeks.org/problems/satisfy-the-equation5847/1

class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        vector<int> ans(4, INT_MAX);
        map<int, pair<int, int>> mp;
        for(int i = 0; i < N-1; i++){
            for(int j = i+1; j < N; j++){
                if(mp.find(A[i]+A[j]) == mp.end()){
                    mp[A[i]+A[j]] = {i, j};
                    continue;
                }
                auto p = mp[A[i]+A[j]];
                if(p.first != i && p.second != j && p.first != j && p.second != i){
                    vector<int> temp;
                    temp.push_back(p.first);
                    temp.push_back(p.second);
                    temp.push_back(i);
                    temp.push_back(j);
                    if(ans[0] == INT_MAX){
                        for(int k = 0; k < 4; k++){
                            ans[k] = temp[k];
                        }
                    } else {
                        bool replace = false;
                        // made mistake here
                        // checking that which one has the smallest 
                        // lexicographical order, ans or temp
                        for(int k = 0; k < 4; k++){
                            if(ans[k] > temp[k]){
                                replace = true;
                                break;
                            } else if(ans[k] < temp[k]){
                                break;
                            }
                        }
                        if(replace){
                            for(int k = 0; k < 4; k++){
                                ans[k] = temp[k];
                            }
                        }
                    }
                }
            }
        }
        if(ans[0] == INT_MAX){
            return {-1, -1, -1, -1};
        }
        return ans;
    }
};

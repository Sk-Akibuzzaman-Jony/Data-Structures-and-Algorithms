class Solution {
  public:
    string constructSmallestString(string A) {
        
        vector<int> freq(26, 0);
        
        for(char x : A){
            freq[x-'a']++;
        }
        
        string B = "", C = "";
        int s = 0;
        while(s < A.size()){
            if(B.size() == 0){
                freq[A[s]-'a']--;
                B.push_back(A[s++]);
            }
            
            int check = B.back()-'a';
            bool flag = true;
            
            for(int i = 0; i < check; i++){
                if(freq[i] != 0){
                    flag = false;
                    break;
                }
            }
            
            if(flag == true){
                C.push_back(B.back());
                B.pop_back();
            } else {
                freq[A[s]-'a']--;
                B.push_back(A[s++]);
            }
        }
        
        while(!B.empty()){
            C.push_back(B.back());
            B.pop_back();
        }
        
        return C;
    }
};

// https://www.geeksforgeeks.org/problems/search-pattern0205/1
// Video -> https://youtu.be/qases-9gOpk?si=HF7blYpbDWYF5NcP

class Solution
{
    void computeLPS(string& pat, vector<int>& LPS, int M){
        int length = 0;
        int i = 1;
        while(i < M){
            if(pat[i] == pat[length]){
                length++;
                LPS[i] = length;
                i++;
            } else {
                if(length != 0){
                    length = LPS[length-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    public:
        vector <int> search(string pat, string txt)
        {
            int M = pat.length();
            int N = txt.length();
            
            vector<int> LPS(M, 0);
            computeLPS(pat, LPS, M);
            
            
            //KMP Algo
            int i = 0, j = 0;
            vector<int> res;
            
            while(i < N){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                
                if(j == M){
                    res.push_back(i-j+1);
                    j = LPS[j-1];
                } else if(txt[i] != pat[j]){
                    if(j != 0){
                        j = LPS[j-1];
                    } else {
                        i++;
                    }
                }
            }
            
            return res;
            
        }
     
};

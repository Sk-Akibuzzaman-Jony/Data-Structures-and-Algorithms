// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution {
	public:
		string FirstNonRepeating(string str){
		    queue<int> q;
		    vector<int> v(26, 0);
		    string ans = str;
		    int n = str.length();
		    for(int i = 0; i < n; i++){
		       q.push(i);
		       v[str[i]-'a']++;
		       while(!q.empty() && v[str[q.front()]-'a'] > 1){
		           q.pop();
		       }
		       if(!q.empty()){
		           ans[i] = str[q.front()];
		       } else {
		           ans[i] = '#';
		       }
		    }
		    return ans;
		}

};

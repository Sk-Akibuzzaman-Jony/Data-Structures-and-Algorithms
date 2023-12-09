#include <bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
  char data;
  TrieNode* arr[26] = {NULL};
  bool isTerminal;

  TrieNode(char data){
    this->data = data;
    isTerminal = false;
  }
};

void insert(TrieNode* root, string str){
  if(str.size() == 0){
    root->isTerminal = true;
    return;
  }

  char ch = str[0];
  int idx = ch-'a';
  TrieNode* child;
  if(root->arr[idx] != NULL){
    child = root->arr[idx];
  } else {
    root->arr[idx] = new TrieNode(ch);
    child = root->arr[idx];
  }
  insert(child, str.substr(1));
}

void solve(TrieNode* root, string& temp, vector<string>& output){
  if(root->isTerminal){
    output.push_back(temp);
  }
  for(int i = 0; i < 26; i++){
    if(root->arr[i] != NULL){
      temp += i+'a';
      solve(root->arr[i], temp, output);
      temp.pop_back();
    }
  }
}


vector<vector<string>> getSuggestions(TrieNode* root, string str){
  vector<vector<string>> ans;
  string temp = ""; 
  TrieNode* prev = root;
  for(char x : str){
    int idx = x-'a';
    temp += x;
    TrieNode* curr = prev->arr[idx];
    if(curr != NULL){
      vector<string> output;
      solve(curr, temp, output);
      ans.push_back(output);
      prev = curr;
    }
  }
  return ans;
}

int main() {
  TrieNode* root = new TrieNode('-');

  insert(root, "code");
  insert(root, "coder");
  insert(root, "codehelp");
  insert(root, "codingninja");
  insert(root, "coding");

  vector<vector<string>> ans = getSuggestions(root, "coder");

  for(auto x : ans){
    for(auto j : x){
      cout << j << " ";
    }
    cout << endl;
  }

}

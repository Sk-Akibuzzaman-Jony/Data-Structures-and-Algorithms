#include <bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
  char data;
  bool isTerminal;
  TrieNode* arr[26] = {NULL};

  TrieNode(char data){
    this->data = data;
    this->isTerminal = false;
  }
};

void insert(TrieNode* root, string newData){
  if(newData.length() == 0){
    root->isTerminal = true;
    return;
  }
  char ch = newData[0];
  int idx = ch - 'A';
  TrieNode* child;
  //checking if the char is already present
  if(root->arr[idx] != NULL){
    child = root->arr[idx];
  } 
  // if its not present then create a new one
  else {
    root->arr[idx] = new TrieNode(ch);
    child = root->arr[idx];
  }

  insert(child, newData.substr(1));
}

bool search(TrieNode* root, string str){
  if(str.length() == 0){
    return root->isTerminal;
  }

  char ch = str[0];
  int idx = ch-'A';
  TrieNode* child;
  if(root->arr[idx] != NULL){
    child = root->arr[idx];
  } else {
    return false;
  }
  return search(child, str.substr(1));
}

int main() {
  TrieNode* root = new TrieNode('-');
  insert(root, "CODING");
  insert(root, "CODE");
  insert(root, "CODER");
  insert(root, "CODEHELP");

  if(search(root, "CODE")){
    cout << "present" << endl;
  } else {
    cout << "absent" << endl;
  }
}

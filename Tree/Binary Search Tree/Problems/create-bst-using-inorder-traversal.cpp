#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* makeBSTFromInorder(vector<int>& inorder, int l, int h){
  if(l-h == 0){
    Node* newNode = new Node(inorder[l]);
    return newNode;
  }

  int mid = l+(h-l)/2;
  Node* midNode = new Node(inorder[mid]);
  midNode->left = makeBSTFromInorder(inorder, l, mid-1);
  midNode->right = makeBSTFromInorder(inorder, mid+1, h);
  return midNode;
  
}

void printInorder(Node* root){
  if(root == NULL){
    return;
  }
  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

void* levelOrderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    if(temp == NULL){
      cout << endl;
    if(!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if(temp->left != NULL){
        q.push(temp->left);
      }
      if(temp->right != NULL){
        q.push(temp->right);
      }
    }
  }
  cout << endl;
}

int main() {
  vector<int> inorder = {1,2,3,4,5,6,7};
  Node* ans = NULL;
  ans = makeBSTFromInorder(inorder, 0, inorder.size()-1);
  cout << "Printing In Order trversal : " << endl;
  printInorder(ans);
  cout << endl;

  cout << "Printing Level Order trversal : " << endl;
  levelOrderTraversal(ans);
  cout << endl;
  return 0;
}
  


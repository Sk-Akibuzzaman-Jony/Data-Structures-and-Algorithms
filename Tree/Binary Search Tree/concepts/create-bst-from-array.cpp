#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
  }
};

Node* insertIntoBST(int val, Node* &root){
  if(root == NULL){
    return new Node(val);
  }
  if(val < root->data){
    root->left = insertIntoBST(val, root->left);
  }
  if(val > root->data){
    root->right = insertIntoBST(val, root->right);
  }
  return root;
}

void makeBST(Node* &root, vector<int> nums){
  for(int x : nums){
    root = insertIntoBST(x, root);
  }
}

void printPreorder(Node* root){
  if(root == NULL){
    return;
  }
  cout << root->data << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printInOrder(Node* root){
  if(root == NULL){
    return;
  }
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}

int main() {
  vector<int> nums;
  Node* root = NULL;
  int temp = INT_MIN;
  while(true){
    cin >> temp;
    if(temp == -1) break;
    nums.push_back(temp);
  }
  makeBST(root, nums);

  cout << "pre-order traversal" << endl;
  printPreorder(root);
  cout << endl;
  cout << "in-order traversal" << endl;
  printInOrder(root);
}

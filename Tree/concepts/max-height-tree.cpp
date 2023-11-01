#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

Node* buildTree(){
  int data;
  cout << "Enter data - " << endl;
  cin >> data;

  if(data == -1){
    return NULL;
  }

  Node* root = new Node(data);
  cout << "Enter data for left part of "<< data <<" node" << endl; 
  root->left = buildTree();

  cout << "Enter data for right part of "<< data <<" node" << endl;
  root->right = buildTree();

  return root;
}

int getHeight(Node* root){
  if(root == NULL){
    return 0;
  }

  int height = 1+(max(getHeight(root->left), getHeight(root->right)));
  return height;
}

int main() {
  Node* root = NULL;

  root = buildTree();

  cout << getHeight(root);
  
  return 0;
}

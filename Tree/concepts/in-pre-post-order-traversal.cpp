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

void inOrderTraversal(Node* root){
    if(root == NULL){
      return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(root == NULL){
      return;
    }
  
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

void postOrderTraversal(Node* root){
    if(root == NULL){
      return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
  Node* root = NULL;

  root = buildTree();

  inOrderTraversal(root);
  cout << endl;

  preOrderTraversal(root);
  cout << endl;

  postOrderTraversal(root);
  cout << endl;
  
  return 0;
}

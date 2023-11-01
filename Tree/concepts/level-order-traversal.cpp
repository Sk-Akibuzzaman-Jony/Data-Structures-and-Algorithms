#include <iostream>
#include <queue>
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

void* levelOrderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    cout << temp->data << " ";
    if(temp->left != NULL){
      q.push(temp->left);
    }
    if(temp->right != NULL){
      q.push(temp->right);
    }
  }
  cout << endl;
}

int main() {
  Node* root = NULL;

  root = buildTree();

  levelOrderTraversal(root);
  
  return 0;
}

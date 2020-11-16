#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct tree{
  int data;
  tree* left;
  tree* right;
  tree(int x){
    data=x;
    left=NULL;
    right=NULL;
  }
};

tree* create_Node(int x){
  tree *node = new tree(x);
  return node;
}

void Recursive_inorder(struct tree *root){
  if(root==NULL)
    return;
  Recursive_inorder(root->left);
  cout<<root->data<<" ";
  Recursive_inorder(root->right);
}

void Itreative_inorder(struct tree *root){
  tree *curr=root;
  stack<tree*> st;
  
  while(!st.empty() || curr !=NULL){
    if(curr){
      st.push(curr);
      curr=curr->left;
    }
    else{
      tree* tmp = st.top();
      st.pop();
      cout<<tmp->data<<" ";
      curr=tmp->right;
    }
  }
  
  
}


int main(){
  tree *root = create_Node(1);
  root->left = create_Node(2);
  root->right = create_Node(3);
  root->right->left = create_Node(4);
  root->right->right = create_Node(5);
  Recursive_inorder(root);
  cout<<endl;
  Itreative_inorder(root);
  return 0;
}
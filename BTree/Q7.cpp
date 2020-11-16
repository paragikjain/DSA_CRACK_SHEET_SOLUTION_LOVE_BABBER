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

void Recursive_preorder(struct tree *root){
  if(root==NULL)
    return;
  
  cout<<root->data<<" ";
  Recursive_preorder(root->left);
  Recursive_preorder(root->right);

}

void Itreative_preorder(struct tree *root){
  stack<tree *> st;
  st.push(root);
  while(!st.empty()){
    tree *tmp=st.top();
    st.pop();
    cout<<tmp->data<<" ";
    if(tmp->right)
      st.push(tmp->right);
    if(tmp->left)
      st.push(tmp->left);
  }
}


int main(){
  tree *root = create_Node(1);
  root->left = create_Node(2);
  root->right = create_Node(3);
  root->left->left = create_Node(4);
  root->left->right = create_Node(5);
  Recursive_preorder(root);
  cout<<endl;
  Itreative_preorder(root);
  return 0;
}
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

void print_level_order(struct tree *root){

  queue<tree *> Q;
  Q.push(root);
  while(!Q.empty()){
     tree * tmp = Q.front();
     Q.pop();
     cout<<tmp->data<<" ";
     if(tmp->left)
       Q.push(tmp->left);
     if(tmp->right)  
       Q.push(tmp->right);
  }

  cout<<endl;

}

void create_mirror(struct tree* root,struct tree** mirror){
  if(root==NULL){
    mirror=NULL;
    return;
  }
  *mirror = create_Node(root->data);
  create_mirror(root->right,&((*mirror)->left));
  create_mirror(root->left,&((*mirror)->right));
}

int main(){
  tree *root = create_Node(1);
  root->left = create_Node(2);
  root->right = create_Node(3);
  root->left->left = create_Node(4);
  root->left->right = create_Node(5);
  print_level_order(root);
  tree *mirror = NULL;
  create_mirror(root,&mirror);
  print_level_order(mirror);
  return 0;
}
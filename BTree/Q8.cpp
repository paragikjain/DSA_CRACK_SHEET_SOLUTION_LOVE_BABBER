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

void Recursive_postorder(struct tree *root){
  if(root==NULL)
    return;
  Recursive_postorder(root->left);
  Recursive_postorder(root->right);
  cout<<root->data<<" ";
}

void Itreative_postorder(struct tree *root){
  stack<tree*> st;
  stack<int>  output;
  st.push(root);
  while(!st.empty()){
      tree *tmp =st.top();
      st.pop();
      output.push(tmp->data);
      if(tmp->left)
        st.push(tmp->left);
      if(tmp->right)
        st.push(tmp->right);  
  }
  while(!output.empty()){
    cout<<output.top()<<" ";
    output.pop();
  }

}


int main(){
  tree *root = create_Node(1);
  root->left = create_Node(2);
  root->right = create_Node(3);
  root->left->left = create_Node(4);
  root->left->right = create_Node(5);
  Recursive_postorder(root);
  cout<<endl;
  Itreative_postorder(root);

  return 0;
}
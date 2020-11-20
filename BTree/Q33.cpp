#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *left;
  Node *right;
  Node(int x){
    data = x;
    left = NULL;
    right = NULL;
  }
};
void find_kth_ancestor(Node *root,int node, int *k,int *output){
  static int flag=0;
  if(root == NULL)
    return;
  if(root->data==node){
    flag=1;
    return;
  }
  if(flag == 1){
    return;
  }
  
  find_kth_ancestor(root->left,node,k,output);
  find_kth_ancestor(root->right,node,k,output);

  if(flag==1){
    // cout<<root->data<<" "<<*k<<endl;    
    *k =*k-1;
  }
  if(*k==0){
    *output = root->data;
  }
}
int main(){
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->left->left = new Node(6);
  root->left->right->left = new Node(7);
  int output;

  //input 1
  int k = 2;
  find_kth_ancestor(root,4,&k,&output);
  cout<<output;  


//if you want to run all input in one go  you need not use static int in above function
//   //input 2
//   k = 1;
//   find_kth_ancestor(root,3,&k,&output);   
//   cout<<output;  

//  //input 3
//   k = 1;
//   find_kth_ancestor(root,7,&k,&output);   
//   cout<<output;    
  //finding kth ancestor of 4

  return 0;
}
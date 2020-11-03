#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int x){
    data=x;
    next=NULL;
  }
};

Node* swap_last2first(Node *head){
 Node *curr=head->next,*prev=head;
 while(curr->next!=NULL){
   prev=curr;
   curr=curr->next;
 }
 curr->next=head;
 prev->next=NULL;
 return curr;
}

int main(){
  Node *test,*head;
  int n,value;
  //input section
  cin>>n;
  cin>>value;
  head = new Node(value);
  test=head;
  for(int i=1;i<n;i++){
    Node *tmp;
    cin>>value;
    tmp=new Node(value);
    test->next=tmp;
    test=test->next;
  }
  //END of input section
  
  head=swap_last2first(head);
  
  // Printing all nodes
  Node *taverse=head;
  while(taverse!=NULL){
    cout<<taverse->data<<" ";
    taverse=taverse->next;
  }
  //End of printing nodes

  return 0;
}
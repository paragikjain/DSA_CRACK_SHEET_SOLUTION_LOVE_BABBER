#include <iostream>
using namespace std;
 struct Node{
   int val;
   Node *next;

   Node(int x){
     val = x;
     next=NULL;
   }
 };


struct Node* reverse_ll(Node * prev,Node * curr){
  Node *next=NULL;
  if(curr==NULL){
    return prev;
  }
  next=curr->next;
  curr->next=prev;
  Node *ret=reverse_ll(curr,next);
  return ret;
}

 int main(){
   //enter values in to link list
   int n;
   Node *head=NULL,*tail=NULL;
   cin>>n;
   int first;
   cin>>first;
   head=new Node(first);
   tail=head;
   for(int i=1;i<n;i++){
     int tmp;
     cin>>tmp;
     tail->next =new Node(tmp);
     tail=tail->next;
   }
   Node *final= reverse_ll(NULL,head);
   while(final!=NULL){
     cout<<final->val<<" ";
     final=final->next;
   }
 }
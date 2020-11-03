// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


Node* reverse(Node* head){
    Node* prev=NULL,*curr=head,*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    return prev;
}
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //find the middle of link list
    int count=0;
    Node *slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* ll2 = reverse(slow->next);
    slow->next=NULL;
    Node* ll1=head;
    while(ll1 && ll2){
        if(ll1->data != ll2->data){
            return false;
        }
        ll1=ll1->next;
        ll2=ll2->next;
    }
    return true;
}
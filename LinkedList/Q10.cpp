// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    //reverse first link list
    Node *fr_curr=first,*fr_prev=NULL,*fr_next=NULL;
    int fr_count=0;
    while(fr_curr!=NULL){
        fr_next=fr_curr->next;
        fr_curr->next=fr_prev;
        fr_prev=fr_curr;
        fr_curr=fr_next;
        fr_count+=1;
    }
    first=fr_prev;
    //return first;
    
    //reverse second link list
    Node *sc_curr=second,*sc_prev=NULL,*sc_next=NULL;
    int sc_count=0;
    while(sc_curr!=NULL){
        sc_next=sc_curr->next;
        sc_curr->next=sc_prev;
        sc_prev=sc_curr;
        sc_curr=sc_next;
        sc_count+=1;
    }
    second=sc_prev;
    //return second;
    
    //adding each ll node and storing into new link list
    int carry=0,first_itreation=1;
    Node *ret,*result,*prev;
 
    while(first || second){
        int sum=carry+(first?first->data:0)+(second?second->data:0);
        //cout<<sum<<endl;
        carry=sum/10;
        sum=sum%10;
   
        result=new Node(sum);
        if(first_itreation==1){
            first_itreation=0;
            ret=result;
        }
        else{
            prev->next=result;
        }
        prev=result;
        result=result->next;
        if(first)
        first=first->next;
        if(second)
        second=second->next;
    }
    if(carry>0){
        result=new Node(carry);
        prev->next=result;
    }
    
    //reverse back output
    Node *out_curr=ret,*out_prev=NULL,*out_next=NULL;
    while(out_curr!=NULL){
        out_next=out_curr->next;
        out_curr->next=out_prev;
        out_prev=out_curr;
        out_curr=out_next;
    }
    ret=out_prev;
    
    return ret;
    
}

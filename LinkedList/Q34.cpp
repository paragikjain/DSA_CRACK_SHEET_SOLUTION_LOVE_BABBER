#include<iostream>

using namespace std;


struct Node 
{ 
    int data; 
    struct Node* next; 
    Node(int x){
        data=x;
        next=NULL;
    }
}; 

void printList(struct Node *node) 
{ 
    while(node != NULL) 
    { 
        printf("%d", node->data); 
        if(node->next) 
            printf(" "); 
        node = node->next; 
    } 
    printf("\n"); 
} 




void solution()
{
    // Driver code for taking input
    int n,x;
    cin>>n;
    cin>>x;
    struct Node* head = new Node(x);
    Node *curr=head;
    for(int i=1;i<n;i++)
    {
      cin>>x;
      Node * tmp=new Node(x);
      curr->next=tmp;
      curr=tmp;
      
    }
    
    
    //logic starts from here
    // I have move all even element to head so i need to reverse
    //but better move all odd at end so no need to reverse also
    //adding all even to head
    int i=head->data%2==0?1:0;
    curr =head->next;
    Node *prev=head;
    while(curr!=NULL){
        Node *next=curr->next;
        if(curr->data%2==0){
          prev->next=curr->next;
          curr->next=head;
          head=curr;
          i++;
        }
        else
          prev=curr;
        curr=next;
    }
    
    //reverse ll till all nodes are even
    curr=head,prev=NULL;
    Node *next=NULL;
    int k=0;
    while(curr!=NULL && i!=k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        k++;
    }
    if(i>0){
     head->next=next;
     head=prev;
    }
     printList(head);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solution();
        
    }
}
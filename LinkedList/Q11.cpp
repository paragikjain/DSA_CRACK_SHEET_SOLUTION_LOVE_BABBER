// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node *tmp1=head1,*tmp2=head2,*output,*tmp3;
    int first=1;
     
    while(tmp1!=NULL && tmp2!=NULL){
        
        if(tmp1 && tmp1->data<tmp2->data) 
          tmp1=tmp1->next;
        else if(tmp2 && tmp2->data<tmp1->data)
          tmp2=tmp2->next;
         else{
           if(first==1){
             output= new Node(tmp1->data);
             tmp3=output;
             first=0;
           }
           else{
               Node *x=new Node(tmp1->data);
               tmp3->next=x;
               tmp3=tmp3->next;
           }
           tmp2=tmp2->next;
           tmp1=tmp1->next;
         }
    }
    
    return  output;
}
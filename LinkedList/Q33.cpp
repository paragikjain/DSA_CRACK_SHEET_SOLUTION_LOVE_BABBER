// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node *compute(Node *head);

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node* reverseList(Node *head){
    Node *curr=head,*prev=NULL,*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node *compute(Node *head)
{
    head=reverseList(head);
    
    //find the max till now and if next is smaller then next till now drop that
/* Initialize max */
    struct Node* current = head;
    struct Node* maxnode = head;
    struct Node* temp;
 
    while (current != NULL && 
           current->next != NULL) 
    {
        /* If current is smaller than max,
        then delete current */
        if (current->next->data < maxnode->data) 
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
 
        /* If current is greater than max, 
            then update max and move current */
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
    
    //agian reverse back original list
    head=reverseList(head);

    return head;
}


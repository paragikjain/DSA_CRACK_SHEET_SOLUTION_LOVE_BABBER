// C++ program to rotate a Doubly linked 
// list counter clock wise by N times 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
struct Node { 
	char data; 
	struct Node* prev; 
	struct Node* next; 
}; 

// This function rotates a doubly linked 
// list counter-clockwise and updates the 
// head. The function assumes that N is 
// smallerthan size of linked list. It 
// doesn't modify the list if N is greater 
// than or equal to size 
Node* rotate(struct Node** head_ref, int N) 
{ 

    Node *curr=*head_ref,*prev=NULL,*next=NULL;
    int count=0;
    while(curr!=NULL && count<N){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
        count++;
    }
    
    if(next!=NULL){
        (*head_ref)->next=rotate(&next,N);
    }
    
    return prev;
  
} 

// Function to insert a node at the 
// beginning of the Doubly Linked List 
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->prev = NULL; 
	new_node->next = (*head_ref); 
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 
*head_ref = new_node; 
} 

/* Function to print linked list */
void printList(struct Node* node) 
{ 
	while (node->next != NULL) { 
		cout << node->data << " "
			<< "<=>"
			<< " "; 
		node = node->next; 
	} 
	cout << node->data; 
} 

// Driver's Code 
int main(void) 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	/* Let us create the doubly 
	linked list a<->b<->c<->d<->e */
	push(&head, 'e'); 
	push(&head, 'd'); 
	push(&head, 'c'); 
	push(&head, 'b'); 
	push(&head, 'a');
  push(&head, '0'); 

	int N =3; 

	cout << "Given linked list \n"; 
	printList(head); 
	head=rotate(&head, N); 

	cout << "\nRotated Linked list \n"; 
	printList(head); 

	return 0; 
} 

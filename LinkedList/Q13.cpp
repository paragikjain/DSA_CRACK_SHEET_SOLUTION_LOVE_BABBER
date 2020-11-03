// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* findmid(Node *head){
  if(head==NULL || head->next==NULL)
    return NULL;  
  Node *slow=head;
  Node *fast=head->next;
  while(fast!=NULL && fast->next!=NULL){
      slow=slow->next;
      fast=fast->next->next;
  }
  return slow;
}
Node *merge(Node *a,Node *b){
    if(a == NULL) {
        return b;
    }
    else if(b == NULL) {
        return a;
    }
    Node* c;
    if(a->data < b->data) {
        c  = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;    
}
Node* mergeSort(Node* head) {
    if(head==NULL || head->next==NULL)
    return head;
    Node *a=head,*mid,*b;
    mid = findmid(a); //finding mid by two pointer
    b = mid->next;    //after getting mid spilt in to 2 ll where secnod ll head is mid->next
    mid->next = NULL; //mid will last node if first ll so mid->next = 0
    a=mergeSort(a); //doing same process and breaking further left array
    b=mergeSort(b); //doing same process and breaking further right array
    Node *c = merge(a,b); //merging left and right array
    return c;
    //we need to find mid point of link list
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
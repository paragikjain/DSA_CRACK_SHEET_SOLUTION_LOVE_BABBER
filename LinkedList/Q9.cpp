// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

Node* addOne(Node *head);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        
        head = addOne(head);
        printList(head); 
    }
    return 0; 
} 
// } Driver Code Ends


//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node* addOne(Node *head) 
{
    Node *test=head;
    int total_ele=0 , total_continue_nine=0;
    while(test!=NULL){
        if(test->data==9){
            total_continue_nine=total_continue_nine+1;
        }
        else{
            total_continue_nine=0;
        }
         test=test->next;
         total_ele=total_ele+1;
      }
      
      //case 1 when no is like 99 or 999 or 9999
      if(total_continue_nine==total_ele){
          Node *x =new Node(1);
          x->next=head;
          head=x;
          x=x->next;
          while(x!=NULL){
              x->data=0;
              x=x->next;
          }
          return head;
      }
      
      //case 2 when no is like 1099 or 879 or 176 
      
      int start=total_ele-total_continue_nine;
      Node *tmp=head;
      for(int i=1;i<=total_ele;i++){
        if(i==start){
            tmp->data+=1;
        }
        if(i>start){
            tmp->data=0;
        }
        tmp=tmp->next;
      }
      return head;
}
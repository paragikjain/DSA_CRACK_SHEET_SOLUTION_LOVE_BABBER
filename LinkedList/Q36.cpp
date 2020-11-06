#include<iostream>
#include <bits/stdc++.h> 


using namespace std;

struct Node{
    char data;
    Node *next;
    Node(char x){
        data=x;
        next=NULL;
    }
};

void solution()
{
    

    int n;
    cin>>n;
    unordered_map<int, int> hash;  //for storing freqvacny of char;
    Node *head,*curr;    // store unique char in list
    char x;        
    //inserting has value to all the data strcutures;
    cin>>x;
    head=new Node(x);
    hash[x]++;
    //cout<<hash[x];
    cout<<x<<" ";
    curr=head;
    Node *root = head;
    int signal=0;
    //adding rest of elements
    for(int i=1;i<n;i++){
        cin>>x;
        hash[x]++;
        //cout<<hash[x]<<endl;
        if(hash[x]<=1){
          Node *tmp=new Node(x);
          curr->next=tmp;
          curr=tmp;
          if(root==NULL){
           root=curr;
           signal=1;
          }
        }
        
        char a;
        if(root)
          a=root->data;
        else
          a='A';
        while(root!=NULL){
            if(x==a && hash[root->data]>1 ){
              //cout<<"hi";
              root=root->next;
              signal=0;
            }
            else{
                break;
            }
        }
       if(root==NULL)
          cout<<-1<<" ";
        else
          cout<<root->data<<" ";
        
        
    }
    
    cout<<endl;
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
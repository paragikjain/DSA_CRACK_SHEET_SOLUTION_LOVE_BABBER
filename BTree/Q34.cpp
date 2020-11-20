// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printAllDups(Node* root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}// } Driver Code Ends


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
#include<bits/stdc++.h>
void inOrder(Node* root,vector<int> &v)
{
    if(root==NULL)
     return;
   
    inOrder(root->left,v);
   
    v.push_back(root->data);
   
    inOrder(root->right,v);
}
void traverse(Node* root,map<vector<int>,int> &mp)
{
    if(root==NULL)
      return;
    
    vector<int> v;
    inOrder(root,v);
    sort(v.begin(),v.end());
    mp[v]++;
    
    traverse(root->left,mp);
    
    traverse(root->right,mp);
    
}
void printAllDups(Node* root)
{
    // Code here
    map<vector<int>,int> mp;
    traverse(root,mp);
    int flag=0;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        if(i->second>1)
        {
            vector<int> v=i->first;
            cout<<v[0]<<" ";
            flag=1;
        }
    }
    if(flag==0)
     cout<<"-1"<<" ";
}
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


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function

pair<int,int> soultion(Node *root,int height,int sum){
    if(root==NULL){
        return make_pair(height,sum);
    }
        sum=root->data+sum;
        pair<int,int> tmp1 = soultion(root->left,height+1,sum);
        pair<int,int> tmp2 = soultion(root->right,height+1,sum);
        
        // cout<<tmp1.first<<" "<<tmp2.first<<endl;
        if(tmp1.first>tmp2.first)
        {
            return tmp1;
        }
        else if(tmp2.first>tmp1.first)
        {
            return tmp2;
        }
        else
        {
            if(tmp1.second>tmp2.second)
            {
                return tmp1;
            }else
            {
                return tmp2;
            }
        }
    
}
int sumOfLongRootToLeafPath(Node* root)
{   pair<int,int> tmp;
	tmp=soultion(root,1,0);
    return tmp.second;
}
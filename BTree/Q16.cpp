// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void print_all_left(Node *root, vector<int> &out){
    if(root==NULL)
      return;
      
    //  cout<<root->data<<endl; 
     if(root->left!=NULL  || root->right != NULL) //if both are NULL in that case we will take that node in leaf case so for ignoring repetation this condition has been included
       out.push_back(root->data);
     if(root->left) //if there is left we will always goto left node.
       print_all_left(root->left,out);
     else //if there is no left node we will go to right node and may be next time we will go to left
       print_all_left(root->right,out);
       
}

void print_all_right(Node *root, vector<int> &out){
    if(root==NULL)
      return;
    if(root->right)  
      print_all_right(root->right,out);
    else
      print_all_right(root->left,out);
    if(root->left!=NULL  || root->right != NULL) 
     out.push_back(root->data);
     
}

void print_leaf(Node *root,vector<int> &out){
    if(root==NULL)
      return;
    print_leaf(root->left,out);
    print_leaf(root->right,out);
    if(root->left==NULL  && root->right == NULL){
      out.push_back(root->data);
    }
    
    
}

vector <int> printBoundary(Node *root)
{
     vector <int> out;
     out.push_back(root->data);
     print_all_left(root->left,out);  //priting all left most nodes devluding leaf
     print_leaf(root,out);   //printing all leaf nodes
     print_all_right(root->right,out);  //printing all right most nodes , decluding lefs.
     
     return out;
}
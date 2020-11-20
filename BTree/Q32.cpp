// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/


   
Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
      return NULL;
    if(root->data==n1)
      return root;
    if(root->data==n2)
      return root;
    Node *l=lca(root->left,n1,n2);
    Node *r=lca(root->right,n1,n2);
    if(l && r) return root;
    if(l==NULL && r==NULL) return l;
    if(l) return l;
    if(r) return r;
}

int dist_from_root(Node *root, int k){
    if(root == NULL)
      return 0;
    if(root->data == k){
        return 1;
    }
    int l = dist_from_root(root->left,k);
    int r = dist_from_root(root->right,k);
    if(!(l) && !(r))
      return 0;
    if(l)
      return l+1;
    if(r)
      return r+1;
    
}

int findDist(Node* root, int a, int b) {
    Node* lca_Node = lca(root,a,b);
    int dist_a = dist_from_root(lca_Node, a) - 1;
    int dist_b = dist_from_root(lca_Node, b) - 1;
    // cout<<dist_a<<" "<<dist_b<<" "<<dist_lca<<" "<<lca_data<<endl;
    return (dist_a+dist_b);
}
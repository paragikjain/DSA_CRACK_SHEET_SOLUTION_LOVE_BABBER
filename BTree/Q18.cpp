Node *prevDLL = nullptr, *head = nullptr;
void DLL(Node *root){
    if(root == nullptr){
        return;
    }
    
    DLL(root->left);
    if(head == nullptr){
        head = root;
    }
    else{
        prevDLL->right = root;
        root->left = prevDLL;
    }
    prevDLL = root;
    DLL(root->right);
}
Node * bToDLL(Node *root)
{
    // your code here
    prevDLL = nullptr;
    head = nullptr;
    DLL(root);
    return head;
}
/*
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

 

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
 

Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  
the  resultant binary tree will be
           2
        /     \
       9       4
        \     /
         5   3
         
   */

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int findPosition(int in[], int element, int n){
    for(int i=0; i<n; i++){
        if(in[i] == element) return i;
    }
    return -1;
}
Node* solve(int in[], int post[], int &postorderIndex, int inorderstart, int inorderEnd, int n){
    if(postorderIndex < 0 || inorderstart > inorderEnd) return NULL;
    
    int element = post[postorderIndex--];
    Node* root = new Node(element);
    int position = findPosition(in, element, n);
    
    root -> right = solve(in, post, postorderIndex, position+1, inorderEnd, n);
    root -> left = solve(in, post, postorderIndex, inorderstart, position-1, n);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int postorderIndex = n-1;
    Node* ans = solve(in, post, postorderIndex, 0, n-1, n);
    return ans;
}

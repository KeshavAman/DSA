/*
You are given a Binary tree. You have to count and return the number of leaf nodes present in it.
A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child
A node is a leaf node if both left and right child nodes of it are NULL.
Input Format :
The first line of input contains an integer 'T' representing the number of the test case. Then the test case follows.

The first line of each test case contains elements of the binary tree in the level order form. The input consists of values of nodes separated by a single space in a single line. In case a node is null, we take -1 in its place.

For example, the input for the tree depicted in the below image would be :

20
10 35 
5 15 30 42 
-1 13 -1 -1 -1 -1 -1 
-1 -1
*/

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void inOrder(BinaryTreeNode<int> *root, int &count){
    //base case
    if(root == NULL) return;
    inOrder(root -> left, count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
    inOrder(root -> right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    inOrder(root, count);
    return count;
}

#include <bits/stdc++.h>
using namespace std;
 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this ->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node *buildTree(Node *root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1) return NULL;

    cout<< "Enter data for left: "<<data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter data for inserting in right: "<<data<<endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    //sepretor
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp -> data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inOrder(Node *root){
    //base case
    if(root == NULL) return;

    inOrder(root -> left);
    cout << root -> data <<" ";
    inOrder(root -> right);
}

void preOrder(Node *root){

    //basecase
    if(root == NULL) return;
    cout<<root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(Node *root){

    //basecase
    if(root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout<< root -> data<<" ";
}

int main(){
    Node *root = NULL;

    //creating a tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);

    cout<<endl<<"Inorder traversaling: ";
    inOrder(root);

    cout<<endl<<"preorder traversaling: ";
    preOrder(root);

    cout<<endl<<"postorder traversaling: ";
    postOrder(root);

    return 0;    
}

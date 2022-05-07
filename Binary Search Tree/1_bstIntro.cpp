#include <iostream>
#include<queue>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

//Inserting in BST
Node* insertIntoBST(Node* &root, int data){

    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root -> data){
        root ->right = insertIntoBST(root -> right, data);
    }
    else{
        root -> left = insertIntoBST(root -> left, data);
    }
    return root;

}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBST(root, data);
        cin>>data;
    }
}

//Level Order Traversal
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

//Inorder Traversal
void inOrder(Node *root){
    //base case
    if(root == NULL) return;

    inOrder(root -> left);
    cout << root -> data <<" ";
    inOrder(root -> right);
}

//Min Value
Node* minVal(Node* root){
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

//Max Value
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}

//Deletion
Node* deleteNodeBST(Node* root, int val){
    //base case
    if(root == NULL) return root;

    if(root -> data == val){
        //0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //right child
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        //2 child
        if(root -> left != NULL && root -> right != NULL){
           int mini =  minVal(root -> right)->data;
           root -> data = mini;
           root -> right = deleteNodeBST(root -> right, mini);
           return root;
        }
    }
    else if(root -> data > val){
        root -> left = deleteNodeBST(root -> left, val);
        return root;
    }
    else{
        root -> right = deleteNodeBST(root -> right, val);
        return root;
    }
}

int main(){

    int node;
    Node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    cout<<"Binary Search Tree is "<<endl;
    levelOrderTraversal(root);

    inOrder(root);

    cout<<"Minimum value is -> "<<" "<<minVal(root) -> data<<endl;

    cout<<"Maximum value is -> "<<" "<<maxVal(root) -> data<<endl;

    root = deleteNodeBST(root, 10);
    cout<<"Binary Search Tree is "<<endl;
    levelOrderTraversal(root);

    return 0;
}


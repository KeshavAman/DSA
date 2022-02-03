#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){

    //create new Node
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;

}
//printing linkedlist
void print(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    //created a node
    Node *node1 = new Node(10);
    //cout<< node1 -> data <<endl;
    //cout<< node1 -> next <<endl;

    //pointed head to node
    Node *head = node1;
    print(head);

    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtHead(head, 15);
    print(head);
}
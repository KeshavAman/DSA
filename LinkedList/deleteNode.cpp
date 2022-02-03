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
    //destructor
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for "<< value <<endl;
    }
};

void insertAtHead(Node* &head, int d){
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtMiddle(Node* &head, Node* &tail, int position, int d){

    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    if(temp ->next == NULL){
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert ->next = temp ->next;
    temp ->next = nodeToInsert;
}

void deleteNode(int position, Node* &head){
    //start node
    if(position == 1){
        Node *temp = head;
        head = head -> next;
        //memory free of start node
        temp -> next = NULL;
        delete temp;
    }
    else{
        //delete at middle
        Node *current = head;
        Node *prev = NULL;
        int count = 1;
        while(count < position){
            prev = current;
            current = current -> next;
            count++;
        }
        prev -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

void print(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }cout<<endl;
}

int main(){
    Node *node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 14);
    insertAtTail(tail, 16);
    print(head);

    insertAtMiddle(head, tail, 1, 9);
    insertAtMiddle(head, tail, 6, 11);
    print(head);

    cout<<"Head -> "<<head -> data<< endl;
    cout<<"Tail -> "<<tail -> data<< endl;

    deleteNode(1, head);
    deleteNode(5, head);
    deleteNode(2, head);
    print(head);
}
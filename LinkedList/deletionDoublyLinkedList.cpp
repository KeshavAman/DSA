#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this -> data = data;
        this->prev = NULL;
        this->next = NULL;
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

//traversing a doubly linkedlist
void print(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp ->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

//getting length of a linkedlist
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

//inserting at head
void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next =  head;
        head -> prev = temp;
        head = temp;

    }
}

//inserting at tail
void insertAtTail(Node* &head, Node* &tail, int d){

    if(tail == NULL){
        Node * temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    } 
}

//insert at any positon
void insertAtMiddle(int position, int d, Node* &head, Node* &tail){
    if(position == 1){
        insertAtHead(head, tail,d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    if(temp ->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert ->next = temp ->next;
    temp ->next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* &head){
    //start node
    if(position == 1){
        Node *temp = head;
        temp ->next ->prev = NULL;
        head = temp -> next;
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
        current -> prev = NULL;
        prev -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head, tail, 12);
    print(head);

    insertAtTail(head, tail, 14);
    insertAtTail(head, tail, 16);
    print(head);

    insertAtMiddle(3,11, head, tail);
    print(head);

    deleteNode(1, head);
    deleteNode(4, head);
    deleteNode(2, head);
    print(head);

    return 0;
}


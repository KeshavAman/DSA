#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for "<< value <<endl;
    }
};

void insertNode(Node* &tail, int element, int data){
    
    //empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp -> next = temp;
    }
    //non empty list
    //assuming that element is already in the list
    else{
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(int value, Node* &tail){
    //list is empty
    if(tail == NULL){
        cout<<"List is already empty!"<<endl;
        return;
    }
    //list is not empty
    else{
        //assuming that value is present in list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        //1 node linked list
        if(curr == prev) tail = NULL;
        //>1 node linked list
        else if(tail == curr) tail = prev;
        curr -> next = NULL;
        delete curr;

    }
}

void print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    do{
        cout<< tail -> data << " ";
        tail = tail -> next;
    }
    while(tail != temp);
    cout<<endl;
}

int main(){

    Node* tail = NULL;

    insertNode(tail, 0, 3);
    print(tail);

    deleteNode(3, tail);
    print(tail);   

    return 0;
}
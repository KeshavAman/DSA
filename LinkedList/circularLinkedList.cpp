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

void print(Node* &tail){
    Node* temp = tail;
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

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);    

    return 0;
}
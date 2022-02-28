#include<bits/stdc++.h>
using namespace std;

class Stack{
    // properties
    public:
        int *arr;
        int size;
        int top;

    // behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack overflow "<<endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack underflow "<<endl;
        }
    }
    int peek(){
        if(top >= 0) return arr[top];
        else{
            cout<<"stack is empty "<<endl;
            return -1;
        }
    }
    bool empty(){
        if(top == -1) return true;
        else return false;
    }
};

int main(){

    Stack st(5);
    

    st.pop();
   
    cout<<"Top element of stack -> "<<st.peek() <<endl;

    if(st.empty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}
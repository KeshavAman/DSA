#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;

    q.push(11);
    q.push(14);
    q.push(12);

    cout<<"Size of queue is -> "<<q.size()<<endl;

    cout<<q.front()<<endl;

    q.pop();

    cout<<"Size of queue is -> "<<q.size()<<endl;

    cout<<q.front()<<endl;


    return 0;
}
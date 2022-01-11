#include<iostream>
using namespace std;
int main(){
    int n=5;
    int s = n-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<s; j++){
            cout<<" ";
        }
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }cout<<endl;
        s--;
    }
    s = 0;
    for(int i=n; i>0; i--){
        for(int j=0; j<s; j++){
            cout<<" ";
        }
        for(int j=0; j<i; j++){
            cout<<"* ";
        }cout<<endl;
        s++;
    }
    return 0;
}
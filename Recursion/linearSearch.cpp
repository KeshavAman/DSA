#include<iostream>
using namespace std;

bool search(int *arr,int size, int key){
    if(size == 0) return false;
    if(arr[0] == key) return true;
    else{
        return search(arr+1, size-1, key);
    }
}

int main(){
    int arr[5] = {2,4,6,8,9};
    bool ans = search(arr, 5, 4);
    if(ans){
        cout<<"Key is present "<<endl;
    }
    else{
        cout<<"Key is not present "<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;

bool binarySearch(int *arr, int size, int key, int start,int end){

        if(start <= end) return true;
        int mid = start + (end - start)/2;
        if(arr[mid] == key) return true;
        else if(arr[mid] > key) return binarySearch(arr, size, key, mid+1, end);
        else return binarySearch(arr, size, key, start, mid-1);
}

int main(){
    int arr[6] = {2,4,6,7,8,12};
    int size = 6;
    int ans = binarySearch(arr, size, 2, 0, size-1);
    if(ans){
        cout<<"Key is present "<< endl;
    }
    else{
        cout<< "Key is not present "<<endl;
    }
    return 0;
}
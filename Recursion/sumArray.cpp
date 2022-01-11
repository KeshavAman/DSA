#include<iostream>
using namespace std;
int getSum(int *arr, int size){
    int sum = 0;
    if(size==0) return sum;
    if(size == 1) return arr[0];
    sum = arr[0] + getSum(arr+1,size-1);
    return sum ;
}
int main(){
    int arr[5] = {2,4,6,8,9};
    int sum = getSum(arr,5);
    cout<<"Sum is -> "<<sum<<endl;
}
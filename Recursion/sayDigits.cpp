#include<iostream>
using namespace std;

void sayDigits(int n, string *arr){

    if(n==0) return ; //base case

    //preprocessing
    int digit = n % 10;
    n = n/10;

    sayDigits(n, arr); // recursive call

    cout<<arr[digit]<<" ";
}


int main(){

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cin>>n;

    sayDigits(n,arr);

    return 0 ;
}
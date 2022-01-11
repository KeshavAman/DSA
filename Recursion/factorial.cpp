#include<iostream>
using namespace std;

int factorial(int n){

    if(n==0) return 1; //base case -> without base case it gives segmentation fault
    return n * factorial(n-1); //recursive relation
}

int main(){

    int n ;
    cout << "Enter number : "<<endl;
    cin>>n;
    int ans = factorial(n);

    cout<< "Factorial is -> "<<ans << endl;
    return 0;
}
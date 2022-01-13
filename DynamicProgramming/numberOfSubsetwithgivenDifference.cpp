#include<iostream>
#include<vector>
using namespace std;

int solve(int *arr, int n, int diff){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    int s1 = (diff+sum)/2;

    int ans[n+1][s1+1];
    ans[0][0] = 1;
    for(int i=1; i<=n; i++){
        ans[i][0] = 1;
    }
    for(int i=1; i<=s1; i++){
        ans[0][i] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<s1+1; j++){
            if(arr[i-1] <= j){
                ans[i][j] = ans[i-1][j-arr[i-1]] + ans[i-1][j];
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][s1];
}


int main(){

    int arr[4] = {1,1,2,3};

    cout<<"Count is -> "<<solve(arr,4,1) <<endl;

    return 0;
}
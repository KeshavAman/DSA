#include<iostream>
using namespace std;

int solve(int *arr, int n, int sum){

    int ans[n+1][sum+1];
    ans[0][0] = 1;
    for(int i=1; i<=n; i++){
        ans[i][0] = 1;
    }
    for(int i=1; i<=sum; i++){
        ans[0][i] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= sum){
                ans[i][j] = ans[i-1][j-arr[i-1]] + ans[i-1][j];
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][sum];

}
int main(){
    int arr[5] = {2,5,3,8,10};
    int sum = 10;

    cout<<"Count is -> "<<solve(arr,5,sum) <<endl;
    return 0;
}
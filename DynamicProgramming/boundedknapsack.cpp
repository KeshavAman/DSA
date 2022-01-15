#include<iostream>
using namespace std;

int solve(int *wt,int *val, int n, int w){
    int ans[n+1][w+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(i==0 || j==0){
                ans[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1] <= j){
                ans[i][j] = max(val[i-1]+ans[i][j-wt[i-1]], ans[i-1][j]);
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][w];
}

int main(){

    int w = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    cout<<"Profit is -> "<<solve(wt,val,3,w)<<endl;

    return 0;
}
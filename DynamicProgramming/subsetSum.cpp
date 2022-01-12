bool subsetSumToK(int n, int k, vector<int> &arr) {
    int ans[n+1][k+1];
    for(int i=0; i<=n; i++){
        ans[i][0] = true;
    }
    for(int i=1; i<=k; i++){
        ans[0][i] = false;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<k+1; j++){
            if(arr[i-1] <= j){
                ans[i][j] = ans[i-1][j-arr[i-1]] || ans[i-1][j];
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][k];
}

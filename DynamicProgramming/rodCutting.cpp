//when both price and length is given
int cutRod(vector<int> &price, int n, vector<int>length)
{
    int ans[size+1][n+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                ans[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(length[i-1] <= j){
                ans[i][j] = max(price[i-1]+ans[i][j-length[i-1]], ans[i-1][j]);
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[size][n];
}



//when only price is given
int cutRod(vector<int> &price, int n)
{
    int ans[n+1][n+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                ans[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i <= j){
                ans[i][j] = max(price[i-1]+ans[i][j-i], ans[i-1][j]);
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][n];
}

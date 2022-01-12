int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    int t[n+1][maxWeight+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=maxWeight; j++){
            if(i==0 || j==0){
                 t[i][j] = 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=maxWeight; j++){
            if(weight[i-1] <= j){
                t[i][j] = max(value[i-1]+t[i-1][j-weight[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][maxWeight];
}

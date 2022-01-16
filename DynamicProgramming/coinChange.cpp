//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

//Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans[n+1][amount+1];
        ans[0][0] = INT_MAX-1;
        for(int i=1; i<n+1; i++){
            ans[i][0] = 0;
        }
        for(int i=1; i<amount+1; i++){
            ans[0][i] = INT_MAX-1;
        }
        for(int i=1, j=1; j<amount+1; j++){
            if(j%coins[0]==0){
                ans[i][j] = j/coins[0];
            }
            else{
                ans[i][j] = INT_MAX-1;
            }
        }
        for(int i=2; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1]<=j){
                    ans[i][j] = min(1+ans[i][j-coins[i-1]], ans[i-1][j]);
                }
                else{
                    ans[i][j] = ans[i-1][j];
                }
            }
        }
        if(ans[n][amount]== INT_MAX-1)
        {
            return -1;
        }
        return ans[n][amount];
    }
};
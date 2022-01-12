class Solution {
private:
    bool subsetSum(vector<int>& nums, int sum, int n){
        int ans[n+1][sum+1];
        for(int i=0; i<=n; i++){
            ans[i][0] = true;
        }
        for(int i=1; i<=sum; i++){
            ans[0][i] = false;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1] <= j){
                    ans[i][j] = ans[i-1][j-nums[i-1]] || ans[i-1][j];
                }
                else{
                    ans[i][j] = ans[i-1][j];
                }
            }
        }
        return ans[n][sum];
    }
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
        }
        if( sum % 2 == 0){
            return subsetSum(nums,sum/2,nums.size());
        }
        else{
            return false;
        }
    }
};

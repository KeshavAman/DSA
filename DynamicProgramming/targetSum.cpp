class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
        }
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        int s1 = (sum+target)/2;
        int ans[n+1][s1+1];
        ans[0][0] = 1;
        for(int i=1; i<n+1; i++){
            ans[i][0] = 1;
        }
        for(int i=1; i<s1+1; i++){
            ans[0][i] = 0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<s1+1; j++){
                if(nums[i-1] <= j){
                    ans[i][j] = ans[i-1][j-nums[i-1]] + ans[i-1][j];
                }
                else{
                    ans[i][j] = ans[i-1][j];
                }
            }
        }
        return ans[n][s1];
    }
};

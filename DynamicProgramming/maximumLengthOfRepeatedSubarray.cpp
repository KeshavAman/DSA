//Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

/*
Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans[n+1][m+1];
        int res = 0;
        for(int i=0; i<=n; i++){
            ans[i][0] = 0;
        }
        for(int i=0; i<=m; i++){
            ans[0][i] = 0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(nums1[i-1] == nums2[j-1]){
                    ans[i][j] = 1+ans[i-1][j-1]; 
                    res = max(res, ans[i][j]);
                }
                else{
                    ans[i][j] = 0;
                }
            }
        }
        return res;
    }
};

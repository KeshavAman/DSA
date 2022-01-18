/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
*/

class Solution {
private:
    int lcs(string word1, string word2, int n, int m){
        int ans[n+1][m+1];
        for(int i=0; i<n+1; i++){
            ans[i][0] = 0;
        }
        for(int i=0; i<=m; i++){
            ans[0][i] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    ans[i][j] = 1+ans[i-1][j-1];
                }
                else{
                    ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
                }
            }
        }
        return ans[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        return (n-lcs(word1, word2, n, m))+(m-lcs(word1, word2, n, m));
    }
};

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
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
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        int m = s2.length();
        return lcs(s,s2,n,m);
    }
};

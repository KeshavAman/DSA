/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
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
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        return n-lcs(s,s2,n,n);
    }
};

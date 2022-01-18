/*
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
*/

class Solution{
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
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.length();
	    int m = str2.length();
	    return (n-lcs(str1,str2,n,m)) + (m-lcs(str1,str2,n,m));
	    
	} 
};

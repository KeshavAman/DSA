/*
Problem Statement
You are given a string ‘st’, Your task is to find the length of the longest repeating subsequence such that two subsequences don’t have the same character at the same position.
For Example :
The given string st = AABCBDC.

As you can see there are two repeating longest subsequences “ABC” with the same character but different position. Therefore the required answer is ‘3’ as the length of “ABC” is 3.
*/

int lcs(string a, string b, int n){
    int ans[n+1][n+1];
    for(int i=0; i<=n; i++){
        ans[i][0] = 0;
    }
    for(int i=0; i<=n; i++){
        ans[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1] == b[j-1] && i != j){
                ans[i][j] = 1+ans[i-1][j-1];
            }
            else{
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
    }
    return ans[n][n];
}

int longestRepeatingSubsequence(string st, int n)
{
	string a = st;
    string b = st;
    return lcs(a,b,n);
}


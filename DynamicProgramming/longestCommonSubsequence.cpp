int lcs(string s, string t)
{
	int n = s.length();
    int m = t.length();
    int ans[n+1][m+1];
    for(int i=0; i<=n; i++){
        ans[i][0] = 0;
    }
    for(int i=0; i<=m; i++){
        ans[0][i] = 0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s[i-1] == t[j-1]){
                ans[i][j] = 1+ans[i-1][j-1];
            }
            else{
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
    }
    return ans[n][m];
}

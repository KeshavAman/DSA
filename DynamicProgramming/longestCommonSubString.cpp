//You have been given two strings 'STR1' and 'STR2'. You have to find the length of the longest common substring.
//A string “s1” is a substring of another string “s2” if “s2” contains the same characters as in “s1”, in the same order and in continuous fashion also.

int lcs(string &str1, string &str2){
	int n = str1.length();
 	int m = str2.length();
    int ans[n+1][m+1];
    int res =0;
    for(int i=0; i<=n; i++){
        ans[i][0] = 0;
    }
    for(int i=0; i<=m; i++){
        ans[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
        	if(str1[i-1]==str2[j-1]){
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

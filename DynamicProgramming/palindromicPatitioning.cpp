/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".
*/

class Solution{
int ans[501][501];
private:
bool isPalindrome(string s, int i, int j){
        if(i>j) return true;
        if(s[i]!=s[j]) return false;
        else return isPalindrome(s,i+1,j-1);
    }
    int solve(string s, int i, int j){
        int res = INT_MAX;
        int left,right;
        if(i>=j || isPalindrome(s,i,j)==true) return ans[i][j] = 0;
        
        if(ans[i][j] != -1){
        return ans[i][j];
        }
        
        for(int k=i; k<j; k++){
            if(ans[i][k]!=-1){
                left = ans[i][k];
            }
            else{
                left = solve(s,i,k);
                ans[i][k] = left;
            }
            if(ans[k+1][j]!=-1){
                right = ans[k+1][j];
            }
            else{
                right = solve(s,k+1,j);
                ans[k+1][j] = right;
            }
            int tempAns = 1+left+right;
            res = min(res, tempAns);
        }
        ans[i][j] = res;
        return ans[i][j];
    }
public:
    int palindromicPartition(string str)
    {
        memset(ans,-1,sizeof(ans));
        return solve(str,0,str.length()-1);
    }
};

//When strig is long or more than 1000 characters only leetcode

class Solution {
int ans[2002][2002];
private:
bool isPalindrome(string &s, int i, int j){
        if(i>j) return true;
        if(s[i]!=s[j]) return false;
        else return isPalindrome(s,i+1,j-1);
    }
    
    int solve(string &s, int i, int j){
        int res = INT_MAX;
        int left,right;
        
        if(ans[i][j] != -1){
        return ans[i][j];
        }
        
        if(i>=j) return ans[i][j] = 0;
        
        if(isPalindrome(s,i,j)==true) return ans[i][j] = 0;
        
        for(int k=i; k<j; k++){
            if(isPalindrome(s,i,k)==true){
                res = min(res, 1+solve(s,k+1,j));
            }
        }
        return ans[i][j] = res;
    }
public:
    int minCut(string s) {
        memset(ans,-1,sizeof(ans));
        return solve(s,0,s.length()-1);
    }
};

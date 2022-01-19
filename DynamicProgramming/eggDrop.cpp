/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
*/

class Solution {
int ans[101][10001];
private:
    int solve(int k, int n){
        int mn = INT_MAX;
        int low = 1, high = n;
        if(n==0 || n==1) return n;
        if(k==1) return n;
        
        if(ans[k][n] != -1){
            return ans[k][n];
        }
        else{
            while(low<=high){ // using memorized binary search
                int mid = low+(high-low)/2;
                int a = solve(k-1,mid-1);
                int b = solve(k, n-mid);
                int x = max(a,b)+1;
                mn = min(mn,x);
                if(a>b){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        } 
        return ans[k][n] = mn;
    }
public:
    int superEggDrop(int k, int n) {
        memset(ans,-1,sizeof(ans));
        return solve(k,n);
    }
};

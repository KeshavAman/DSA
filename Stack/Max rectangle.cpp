/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
*/

class Solution{
private:
int largestRectangleArea(int *heights, int n) {
        int area = INT_MIN;
        
        vector<int>next(n);
        next = nextSmallestElement(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallestElement(heights, n);
        
        for(int i=0; i<n; i++){
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
        
            int newArea = l*b;
            area = max(newArea, area);
        }
        return area;
    }
    
    vector<int>nextSmallestElement(int *arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    
    vector<int>prevSmallestElement(int *arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        //area for 1st row
        int area = largestRectangleArea(M[0], m);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                //update row by adding previous row
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else{
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};

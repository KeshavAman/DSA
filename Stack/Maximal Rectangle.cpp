/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
*/

class Solution {
private:
    int largestRectangleArea(vector<int>heights) {
        
        int n = heights.size();
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
    
    vector<int>nextSmallestElement(vector<int>arr, int n){
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
    
    vector<int>prevSmallestElement(vector<int>arr, int n){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0;
        vector<int>histogram(m, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //update row by adding previous row
                if(matrix[i][j] == '1'){
                    histogram[j]++;
                }
                else{
                    histogram[j] = 0;
                }
            }
            area = max(area, largestRectangleArea(histogram));
        }
        return area;
    }
};

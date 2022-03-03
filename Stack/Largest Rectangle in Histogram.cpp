/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
*/

class Solution {
private:
    vector<int>nextSmallestElement(vector<int> arr, int n){
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
    
    vector<int>prevSmallestElement(vector<int> arr, int n){
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
    int largestRectangleArea(vector<int>& heights) {
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
};

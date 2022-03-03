/*
Given a stack with push(), pop(), empty() operations, delete the middle of the stack without using any additional data structure.
Middle: ceil(size_of_stack/2.0)
 

Example 1:

Input: 
Stack = {1, 2, 3, 4, 5}
Output:
ModifiedStack = {1, 2, 4, 5}
Explanation:
As the number of elements is 5 , 
hence the middle element will be the 3rd
element which is deleted
Example 2:

Input: 
Stack = {1 2 3 4}
Output:
ModifiedStack = {1 3 4}
Explanation:
As the number of elements is 4 , 
hence the middle element will be the 2nd
element which is deleted
*/

class Solution
{
    private:
    void solve(stack<int>&s, int size, int count){
        //base case
        if(count == size/2){
            s.pop();
            return;
        }
        int num = s.top();
        s.pop();
        
        //recursive call
        solve(s, size, count+1);
        s.push(num);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0;
        solve(s, sizeOfStack, count);
    }
};

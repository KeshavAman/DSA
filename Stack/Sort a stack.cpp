/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   vector<int>v;
   while(!s.empty()){
       v.push_back(s.top());
       s.pop();
   }
   std::sort(v.begin(), v.end());
   for(int i=0; i<v.size(); i++){
       s.push(v[i]);
   }
}


/*Another way
*/

void sortedInsert(stack<int> &s, int num){
    if(s.empty() || (s.top() < num)){
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(n);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;
    
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack, num);
}

/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
*/

/*
Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        Node* temp = head;
        
        if(head == NULL) return NULL;
        
        while(temp != NULL){
            if(temp -> data == 0) zeroCount++;
            else if(temp -> data == 1) oneCount++;
            else if(temp -> data == 2) twoCount++;
            
            temp = temp -> next;
        }
        temp = head;
        while(temp != NULL){
            if(zeroCount != NULL){
                temp -> data = 0;
                zeroCount--;
            }
            else if(oneCount != NULL){
                temp -> data = 1;
                oneCount--;
            }
            else if(twoCount != NULL){
                temp -> data = 2;
                twoCount--;
            }
            temp = temp -> next;
        }
       return head; 
    }
};

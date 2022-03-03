/*

Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* &left, ListNode* &right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        //merge two sorted linkedlist
        while(left != NULL && right != NULL){
            if(left -> val < right -> val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                temp = right;
                right = right -> next;
                
            }
        }
        while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        
        while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
        
        ans = ans -> next;
        return ans;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        //basecase
        if(head == NULL || head -> next == NULL) return head;
        
        //divide ll into two half
        ListNode* mid = findMiddle(head);
        
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;
        
        //recursive call to sort both half
        left = sortList(left);
        right = sortList(right);
        
        //merge both left and right half
        ListNode* ans = merge(left, right);
        return ans;
    }
};

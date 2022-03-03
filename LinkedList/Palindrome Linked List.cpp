/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
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
    ListNode* getMiddle(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head -> next == NULL) return true;
        //step1 -> find middle
        ListNode* middle = getMiddle(head);
        
        //step2 -> reverse list after middle
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //compare both half
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        while(head2 != NULL){
            if(head1 -> val != head2 -> val) return false;
            else{
                head1 = head1 -> next;
                head2 = head2 -> next;
            }
        }
        
        return true;
    }
};

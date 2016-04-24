234. Palindrome Linked List   
My Submissions QuestionEditorial Solution
Total Accepted: 45328 Total Submissions: 162055 Difficulty: Easy
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

Subscribe to see which companies asked this question


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* func(ListNode* head) {
        if(head->next != NULL) {
            ListNode *tail = func(head->next);
            tail->next = head;
            head->next = NULL;
        }
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        ListNode *newhead = head;
        while(newhead->next != NULL) {
            newhead = newhead->next;
        }
        func(head);
        return newhead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *p, *q;
        p = head;
        q = head;
        while(q != NULL) {
            p = p->next;
            q = q->next;
            if(q != NULL) {
                q = q->next;
            }
        }
        p = reverseList(p);
        while(p != NULL) {
            if(head->val != p->val)
                return false;
            else {
                head = head->next;
                p = p->next;
            }
        }
        return true;
    }
};
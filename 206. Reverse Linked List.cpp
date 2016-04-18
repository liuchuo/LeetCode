206. Reverse Linked List
Reverse a singly linked list.

click to show more hints.

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
    ListNode* reverseList(ListNode* head) {
        stack<int> s;
        ListNode* p = head;
        while(p != NULL) {
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while(p != NULL) {
            p->val = s.top();
            s.pop();
            p = p->next;
        }
        return head;
    }
};



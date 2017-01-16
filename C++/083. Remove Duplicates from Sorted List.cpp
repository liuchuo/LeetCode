83. Remove Duplicates from Sorted List
Total Accepted: 110507 Total Submissions: 302035 Difficulty: Easy
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p = head;
        while(p != NULL &&  p->next != NULL) {
            while (p->next != NULL && p->next->val == p->val) {
                    p->next = p->next->next;
            }
            p = p->next;
        }
        return head;
    }
};
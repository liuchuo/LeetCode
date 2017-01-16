142. Linked List Cycle II 
My Submissions QuestionEditorial Solution
Total Accepted: 72017 Total Submissions: 228808 Difficulty: Medium
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        set<ListNode *> s;
        ListNode *p = head;
        int cnt = 0;
        while(p->next != NULL) {
            s.insert(p);
            if(cnt == s.size()) {
                return p;
            }
            cnt = s.size();
            p = p->next;
        }
        return NULL;
    }
};
203. Remove Linked List Elements 
My Submissions QuestionEditorial Solution
Total Accepted: 59711 Total Submissions: 209326 Difficulty: Easy
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val) {
            head = head->next;
        }
        if(head == NULL) {
            return NULL;
        }
        ListNode *p = head;
        ListNode *q= p->next;
        while(p != NULL && p->next != NULL) {
            q = p->next;
            while(q != NULL && q->val == val) {
                q = q->next;
            }
            p->next = q;
            p = q;
        }
        return head;
    }
};
445. Add Two Numbers II 
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7


题目大意：两个链表l1和l2，返回一个链表，其值为l1与l2的和～
分析：将l1和l2分别放入栈中，这样他们就被倒置了，然后依次出栈将结果相加，（不要忘记考虑进位问题），结果放入新的栈s中，然后将s弹栈，结果放入一个新链表中～～

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, s;
        while(l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!s1.empty() || !s2.empty()) {
            int tempsum = carry;
            if(!s1.empty()) {
                tempsum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                tempsum += s2.top();
                s2.pop();
            }
            carry = 0;
            if(tempsum >= 10) {
                carry = 1;
                tempsum = tempsum - 10;
            }
            s.push(tempsum);
        }
        if(carry == 1)
            s.push(1);
        ListNode* result = new ListNode(0);
        ListNode* cur = result;
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            ListNode* node = new ListNode(top);
            cur->next = node;
            cur = cur->next;
        }
        return result->next;
    }
};
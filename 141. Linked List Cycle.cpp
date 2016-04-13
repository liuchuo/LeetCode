141. Linked List Cycle 
My Submissions QuestionEditorial Solution
Total Accepted: 99549 Total Submissions: 269608 Difficulty: Medium
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question


update v2.0:
//后来想到了一个不赖皮的方法 用 set 存储 判断每次存入 next 结点后 set 的 size()有没有发生变化
//没有发生变化说明这个结点已经被存储过了 就说明是个环
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        set<ListNode *> s;
        ListNode *t;
        t = head;
        int cnt = 0;
        while(t->next != NULL) {
            s.insert(t);
            if(cnt == s.size()) {
                return true;
            }
            cnt = s.size();
            t = t->next;
        }
        return false;
    }
};

version 1.0:
//感觉自己做这道题的方法有点赖皮。。。唔。。。
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *p;
        p = head;
        p->val = 99999999;
        while(p->next != NULL) {
            p = p->next;
            if(p->val != 99999999) {
                p->val = 99999999;
            } else {
                return true;
            }
        }
        return false;
    }
};
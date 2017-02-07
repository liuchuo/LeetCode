382. Linked List Random Node
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();

题目大意：给一个单链表，返回一个随机结点的值，要求每一个结点都有同样的概率被选中～
分析：先求出链表的长度len，然后用rand() % len生成一个0～len-1之间的随机数cnt，然后返回第cnt个结点的值～

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;
    int len;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        len = 1;
        while(head->next != NULL) {
            head = head->next;
            len++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = head;
        int cnt = rand() % len;
        while(cnt--) {
            node = node->next;
        }
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
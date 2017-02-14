109. Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

题目大意：给一个升序单链表，把它转换成一个高度平衡的二叉搜索树～
分析：递归求解，找到中点，将中点的值赋值给根结点，中点之前的链表为根结点的左子树，中点之后的链表为根结点的右子树～
中点以这种方式确定：设立两个指针fast和slow，它们分别从head开始，fast走两步slow走一步，当fast走到最后一个结点的时候slow正好走到中点～

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return func(head, NULL);
    }
    TreeNode* func(ListNode* head, ListNode* tail) {
        ListNode *fast = head, *slow = head;
        if (head == tail) return NULL;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = func(head, slow);
        root->right = func(slow->next, tail);
        return root;
    }
};
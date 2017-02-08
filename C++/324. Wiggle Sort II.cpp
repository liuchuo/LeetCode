324. Wiggle Sort II
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

题目大意：给一个数组，按照nums[0] < nums[1] > nums[2] < nums[3]...的顺序重排序数组～
分析：先给数组排序，然后拷贝一份一样的数组arr。然后p指针从数组中间开始向前，q指针从数组最后一位开始向前，依次赋值给nums[i]和nums[j]——其中i是偶数下标，j是奇数下标～

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> arr = nums;
        int p = (nums.size() - 1) / 2, q = nums.size() - 1;
        for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2) {
            nums[i] = arr[p--];
            if (j < nums.size()) nums[j] = arr[q--];
        }
    }
};
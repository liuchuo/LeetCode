442. Find All Duplicates in an Array
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

分析：题目说不能用额外的空间，就想办法直接利用nums数组标记，考虑到nums数组中的所有数都为正数，那么比如i出现过，把num[i]的值标记为负数，那么每次去看num[i]是正是负就能知道i以前有没有出现过～因为所有数都是1～n的，而下标只能0～n-1，可以把i-1标记成负数来符合这个条件～
所以说可以令当前nums[i]的绝对值是num，如果nums[num-1]这个值是负数，说明以前遇到过num，那么就把num这个数字放入result数组中；如果不是负数，说明以前没有出现过这个数，就把这个数变成自己本身的负数～即：nums[num - 1] = 0 - nums[num - 1];

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            if(nums[num - 1] < 0)
                result.push_back(num);
            else
                nums[num - 1] = 0 - nums[num - 1];
        }
        return result;
    }
};
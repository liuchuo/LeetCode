33. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

题目大意：假设按照升序排列的数组在事先未知的某个关键点上旋转。给一个目标数target，找这个数是否存在于这个序列中，如果存在返回下标，不存在返回-1
分析：二分搜索法，如果当前nums[mid] < nums[l]，说明mid在旋转节点的右边，那么如果target也在mid和r之间就将l = mid + 1表示在mid + 1到r的区域找，否则将r = mid - 1在l到mid - 1的区域寻找；如果当前nums[mid] > nums[r]，说明mid在旋转节点的左边，那么如果target也在l和mid之间就将r = mid - 1，在l～mid-1的区域内寻找，否则在mid+1～r的区域内寻找；否则说明当前区间的顺序是正确的，就判断target和mid的大小关系，如果比mid所指数字大则在右边找，否则在左边找

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            } else if (nums[mid] > nums[r]) {
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
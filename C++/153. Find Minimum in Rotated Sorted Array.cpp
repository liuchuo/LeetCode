153. Find Minimum in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

分析：二分搜索法，即使旋转过了也会一半的任何一个元素始终比另一半的任何一个元素大，所以如果nums[mid] < nums[high]，说明最小元素一定在[left, mid]中，所以令high = mid；否则一定在[mid + 1, high]中，令low = mid + 1～～

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] < nums[high])
                high = mid;
            else
                low = mid + 1;
        }
        return nums[low];
    }
};
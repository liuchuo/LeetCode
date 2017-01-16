34. Search for a Range   
My Submissions QuestionEditorial Solution
Total Accepted: 81209 Total Submissions: 278927 Difficulty: Medium
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Subscribe to see which companies asked this question


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high && nums[low] != target && nums[high] != target) {
            int mid = (high - low) / 2 + low;
            if(nums[mid] < target) {
                low = mid + 1;
            } else if(nums[mid] > target){
                high = mid - 1;
            } else {
                break;
            }
        }
        vector<int> v(2);
        if(low > high) {
            v[0] = -1;
            v[1] = -1;
            return v;
        }
        while(nums[low] != target) {
            low++;
        }
        while(nums[high] != target) {
            high--;
        }
        v[0] = low;
        v[1] = high;
        return v;
    }
};

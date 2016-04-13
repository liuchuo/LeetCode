169. Majority Element 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int temp = 0, maxvalue = 0, ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] == nums[i]) {
                temp++;
                if(temp > maxvalue) {
                    maxvalue = temp;
                    ans = nums[i];
                }
            } else {
                temp = 0;
            }
        }
        return ans;
    }
};
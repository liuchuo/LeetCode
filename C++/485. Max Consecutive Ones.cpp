485. Max Consecutive Ones
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

分析：设立cnt数组，表示在nums[i]处当前连续的1的值，maxn取其最大的值，在遇到nums[i] == 0的时候更新maxn的值。最后还要更新一下防止最后一个是1.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> cnt(nums.size());
        int maxn = 0;
        cnt[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == 0) {
                cnt[i] = 0;
                maxn = max(maxn, cnt[i-1]);
            } else {
                cnt[i] = cnt[i-1] + 1;
            }
        }
        maxn = max(maxn, cnt[nums.size() - 1]);
        return maxn;
    }
};
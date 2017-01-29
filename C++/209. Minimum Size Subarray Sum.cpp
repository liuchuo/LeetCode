209. Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there is not one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

分析：sum为前i个数的和，长度比nums多一个，sum[0] = 0。这样从0开始一直到len，遍历sum计算sum[j]与sum[i]的差大于等于s的时候的j-i长度，把它与minlen比较，如果比minlen小就更新minlen。
一开始minlen的初始化值是len + 1，如果最后minlen的值仍旧为len + 1，说明没有找到这样的minlen满足题意。则直接返回0；否则返回minlen的值～～

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int minlen = len + 1;
        vector<int> sum(len + 1);
        for(int i = 1; i <= len; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        for(int i = 0; i <= len; i++) {
            for(int j = i + 1; j <= len; j++) {
                if(sum[j] - sum[i] >= s) {
                    minlen = min(minlen, j - i);
                    break;
                }
            }
        }
        if(minlen == len + 1)
            return 0;
        return minlen;
    }
};
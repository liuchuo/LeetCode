300. Longest Increasing Subsequence   
My Submissions QuestionEditorial Solution
Total Accepted: 27269 Total Submissions: 79306 Difficulty: Medium
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

update v2.0: //更高效的O(nlogn)方法~
维护一个数组vector<int> v~~
将nums[0]加入数组，对于每一个来的数nums[i]，如果大于v.back()，就将它push入数组~~
否则，就找到第一个比这个数大的位置，将该位置的数字替换为nums[i]~~~~
最终返回v数组的长度~~~就是最长字串的长度啦~~~
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] > v.back()) {
                v.push_back(nums[i]);
            } else {
                *lower_bound(v.begin(), v.end(), nums[i]) = nums[i];
            }
        }
        return v.size();
    }
};

v 1.0：
该方法经由小票票指点~~建立一个和nums数组等长的dp数组
dp数组dp[i]的值表示nums[i]处可以构成的最长字串的长度~~
也就是说，在i下标前面的所有nums值当中，找到所有比nums[i]小的，且dp值最大的那个值，然后加1~~
然后最长递增子序列的长度为所有dp[i]当中最大的值~~~
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n);
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++) {
            int temp = 0;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    temp = max(temp, dp[j]);
                }
            }
            dp[i] = temp + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

53. Maximum Subarray   
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

分析：特例是，当所有数都为负数的时候，要返回一个最小的负数，而非返回0。
设temp的初始化值为nums[0]，i从1一直遍历到len-1：
0.ans始终为temp和ans值中较大的那一个。
1.当当前temp的值为正数的时候，来者nums[i]加temp。//此时如果nums[i]为负数对临时总和temp无贡献，则不会更新ans的值，我们临时把它收入temp的总和当中以备后用。如果nums[i]是正数，对临时总和temp有贡献，那就会更新ans的最大值。
2.当当前temp的值为负数的时候，temp的值直接+nums[i]。//之前的临时总和temp是个负数，对于来者nums[i]来说不管怎样nums[i]如果+temp都是在减少nums[i]，还不如直接将temp=0舍弃前面的负数和，取nums[i]当作当前的临时总和的值。
3.temp如果为0不用考虑怎样都行~

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int ans = nums[0], temp = nums[0];
        for(int i = 1; i < len; i++) {
            if(temp > 0) {
                temp = temp + nums[i];
            } else {
                temp = nums[i];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};


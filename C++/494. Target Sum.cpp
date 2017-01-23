494. Target Sum
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

题目大意：给一个非负的整数数组，可以在每个元素前面加+或者-，给一个目标整数S，求问有多少种不同的添加方式，可以让数组中所有元素在添加符号之后相加的结果为S～
分析：深度优先搜索，尝试每次添加+或者-，当当前cnt为nums数组的大小的时候，判断sum与S是否相等，如果相等就result++。sum为当前cnt步数情况下的前面所有部分的总和～

class Solution {
public:
    int result;
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(0, 0, nums, S);
        return result;
    }
    void dfs(int sum, int cnt, vector<int>& nums, int S) {
        if(cnt == nums.size()) {
            if(sum == S)
                result++;
            return ;
        }
        dfs(sum + nums[cnt], cnt + 1, nums, S);
        dfs(sum - nums[cnt], cnt + 1, nums, S);
    }
};
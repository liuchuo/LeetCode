486. Predict the Winner
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.

题目大意：给一个整型数组，两个人依次从数组中的头或者尾拿一个数，判断是否player1拿到的总数大于或者等于player2～如果是就返回true，否则返回false～
分析：动态规划解决～建立dp[len][len]数组，dp[i][j]表示nums数组中i～j下标间player1能够获得的分数-player2能够获得的分数～最后dp[0][len-1]的正负性即可表明player1是否能赢～
dp[0][len-1]的值通过递归动态规划可得：func(begin, end)返回dp[begin][end]的值，当begin和end相等的时候，dp[begin][end]的值即为nums[begin]（或者nums[end]），如果begin和end不等，那么如果取begin，结果为nums[begin] - dp[begin+1][end]; 如果取end，结果为nums[end] - dp[begin][end-1]，dp[begin][end]取它俩中较大的一个～

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        this->nums = nums;
        int len = nums.size();
        dp.resize(len, vector<int>(len));
        return func(0, len-1) >= 0;
    }
private:
    vector<int> nums;
    vector<vector<int>> dp;
    int func(int begin, int end) {
        dp[begin][end] = begin == end ? nums[begin] : max(nums[begin] - func(begin+1, end), nums[end] - func(begin, end-1));
        return dp[begin][end];
    }
};
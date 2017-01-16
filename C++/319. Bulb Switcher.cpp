319. Bulb Switcher   
My Submissions QuestionEditorial Solution
Total Accepted: 17314 Total Submissions: 42815 Difficulty: Medium
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
Subscribe to see which companies asked this question


可知题意是想判断1~n中那些数的因子个数是奇数
一个数 a = b x c 当 b = c 的时候 a 的因子个数就是奇数
所以就是判断1~n当中有多少个是某数的平方

class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for(int i = 1; i * i <= n; i++) {
            ans++;
        }
        return ans;
    }
};
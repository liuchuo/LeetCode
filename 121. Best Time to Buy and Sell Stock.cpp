121. Best Time to Buy and Sell Stock 
My Submissions QuestionEditorial Solution
Total Accepted: 93802 Total Submissions: 261161 Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minvalue = 99999999;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(minvalue > prices[i]) {
                minvalue = prices[i];
            }
            prices[i] = prices[i] - minvalue;
            if(ans < prices[i]) {
                ans = prices[i];
            }
        }
        return ans;
    }
};
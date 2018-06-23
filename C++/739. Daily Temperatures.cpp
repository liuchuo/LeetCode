739. Daily Temperatures
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

分析：用栈解决，i从0～len-1，每次将栈顶元素小于temperatures[i]的出栈，因为对于出栈的元素来说它已经找到了第一个大于它的值，剩余在栈中的都是未找到大于它本身的值的元素，则继续等待下一个temperatures[i]。每次将temperatures[i]压入栈中，等待接下来遇到比它大的值时出栈～将i与栈顶元素下标的差值保存在栈顶元素的下标所对应的ans中，最后返回ans即可～

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        int len = temperatures.size();
        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            while(!s.empty() && temperatures[i] > s.top().first) {
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push(pair<int, int>(temperatures[i], i));
        }
        return ans;
    }
};
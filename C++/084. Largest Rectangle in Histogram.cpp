class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {    //Monotone Stack
        if (heights.empty())
            return 0;
        heights.push_back(-1);
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i){
            while (stk.size() && heights[stk.top()] > heights[i]){
                int cur = stk.top();
                stk.pop();
                if (stk.empty())
                    ans = max(ans, heights[cur] * i);
                else
                    ans = max(ans, heights[cur] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        return ans;
    }
};
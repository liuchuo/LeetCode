179. Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
题目大意：给一个非负整数数组，求怎样把他们连接起来构成的整数最大～
分析：先把他们转换成字符串数组arr，然后对arr进行排序，排序规则是return (a + b) > (b + a);即a+b拼接起来的字符串应该比b+a拼接起来的字符串大～然后将排序后的arr数组从头到尾连接起来～

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        vector<string> arr(nums.size());
        for(int i = 0; i < nums.size(); i++)
            arr[i] = to_string(nums[i]);
        auto cmp = [](string a, string b) {
            return (a + b) > (b + a);
        };
        sort(arr.begin(), arr.end(), cmp);
       for(int i = 0; i < arr.size(); i++)
            result += arr[i];
        return result[0] == '0' ? "0" : result;
    }
};
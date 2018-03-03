728. Self Dividing Numbers
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.

题目大意：一个自我分裂的数字是一个数字，它可以被每个数字所包含。例如，128是一个自分数，因为128％1 == 0，128％2 == 0和128％8 == 0。而且，一个自分数的数字不允许包含数字零。给定一个较低和较高的数字边界，输出每一个可能的自分数的列表，如果可能的话，包括边界。
分析：将left和right中每一个数字i转为string，对string的每一位取余，如果当前位等于0或者取余结果不为0则flag标记为false，把所有flag为true的数字放入ans数组中返回～

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            string s = to_string(i);
            bool flag = true;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '0' || i % (s[j] - '0') != 0) {
                    flag = false;
                    break;
                }
            }  
            if (flag) ans.push_back(i);
        }
        return ans;
    }
};
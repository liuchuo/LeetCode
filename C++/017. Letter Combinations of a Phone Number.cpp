17. Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

题目大意：给一个数字字符串，求可能出现的电话上的字母组合的所有情况～返回的次序可以不同～
分析：result为要返回的string数组，依次根据digits字符串的数字顺序从左到右遍历的顺序往里面添加字母，每一次都追加在原有result的后面，因为result会改变所以每次设立一个空string数组temp，然后temp根据result中原有的结果向后面继续添加拼接原+新的字符串，然后result = temp进行复制～
如果digits不包含字符，应该返回空的result；否则因为要在原有result基础上拼接添加，所以先在result中push_back一个空串，以便后来的拼接字符串～

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length() == 0)
            return result;
        result.push_back("");
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < digits.size(); i++) {
            string s = v[digits[i] - '0'];
            vector<string> temp;
            for(int j = 0; j < s.length(); j++)
                for(int k = 0; k < result.size(); k++)
                    temp.push_back(result[k] + s[j]);
            result = temp;
        }
        return result;
    }
};
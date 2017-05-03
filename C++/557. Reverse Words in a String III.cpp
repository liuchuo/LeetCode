557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

题目大意：将一个字符串的每个单词反转～
分析：将每个单词放入栈中，当遇到空格或者最后一个字符的时候，说明当前栈内为一个完整的单词，那么就将栈内的单词按字符一个个出栈加入result字符串中，根据flag的值判断是否是第一个单词，如果不是第一个单词就要在result的后面加一个空格～

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        stack<char> word;
        int flag = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') 
                word.push(s[i]);
            if (s[i] == ' ' || i == s.length() - 1) {
                if (flag == 1) result += " ";
                while (!word.empty()) {
                    result += word.top();
                    word.pop();
                    flag = 1;
                }
            }
        }
        return result;
    }
};
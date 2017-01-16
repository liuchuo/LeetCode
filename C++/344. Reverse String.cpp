344. Reverse String 
My Submissions QuestionEditorial Solution
Total Accepted: 6975 Total Submissions: 11764 Difficulty: Easy
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

Subscribe to see which companies asked this question

//方法一：最简单的办法，直接调用 reverse 函数。。
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

//方法二：比较常规的做法，左右两边第一个和倒数第一个调换，第二个和倒数第二个调换...
class Solution {
public:
    string reverseString(string s) {
        for(int i = 0; i < s.length() / 2; i++) {
            swap(s[i], s[s.length() - i - 1]);
        }
        return s;
    }
};


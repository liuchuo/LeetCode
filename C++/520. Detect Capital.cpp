520. Detect Capital
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False

题目大意：判断一个字母是否大小写正确：要么全是大写，要么全是小写，或者首字母大写其他小写，否则不满足题意～
分析：判断word[0]和word[1]的大小写，如果word[0]是小写，那后面必须是小写，如果word[0]是大写word[1]是小写，那后面也必须是小写，如果word[0]是大写word[1]也是大写那么后面必须都是大写～

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() <= 1) return true;
        if (islower(word[0]) || (isupper(word[0]) && islower(word[1]))) {
            for (int i = 1; i < word.length(); i++)
                if (isupper(word[i])) return false;
        } else {
            for (int i = 1; i < word.length(); i++)
                if (islower(word[i])) return false;
        }
        return true;
    }
};
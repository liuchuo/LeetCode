318. Maximum Product of Word Lengths
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

题目大意：给一个string数组，每一个string都是一个单词，只包含小写字母，求问没有相同字母的两个单词的长度乘积最大值是多少～如果不存在这样的两个单词，返回0～
分析：其实只需要知道每个单词包含哪些字母就可以了～反正一共只有26个字母，而整型长度是32位，这样就可以用一个int的32位来体现一个字母有哪些字母～比如说一个单词包含字母b，那么b - a = 1，就把从右往左的第1位置为1～等到把一个单词的所有字母相应位都置为1后，这个整型的值与另一个单词的整型值做“&”运算就可以得知他俩有没有相同的字符了～因为如果做“&”运算后的结果是0，表示没有二进制中的一位同时是1，表示这两个单词是没有相同字符的～这样就能很快判断出最大的长度乘积了～

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> v(words.size());
        int result = 0;
        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words[i].length(); j++)
                v[i] = v[i] | 1 << (words[i][j] - 'a');
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++)
                if((v[i] & v[j]) == 0)
                    result = max(result, (int)(words[i].length() * words[j].length()));
        return result;
    }
};

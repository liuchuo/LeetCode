500. Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
题目大意：给一个单词数组，判断哪些单词是可以由键盘的一行中的字母构成的，返回这些单词～
分析：设立一个集合数组，v[0]、v[1]、v[2]集合分别插入键盘的第1～3行的所有字母的集合（大小写都包括），接着遍历每一个单词，首先判断单词的第一个字母是处于哪一行的，tag表示其所属行数的下标，接着对于单词的每一个字母，判断是否在v[tag]这个集合里面，如果所有的都存在就将这个单词放入result数组中返回～

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        vector<set<char>> v(3);
        string s1 = "QWERTYUIOPqwertyuiop", s2 = "ASDFGHJKLasdfghjkl", s3 = "ZXCVBNMzxcvbnm";
        for (int i = 0; i < s1.length(); i++) v[0].insert(s1[i]);
        for (int i = 0; i < s2.length(); i++) v[1].insert(s2[i]);
        for (int i = 0; i < s3.length(); i++) v[2].insert(s3[i]);
        for (int i = 0; i < words.size(); i++) {
            int tag = -1;
            bool flag = true;
            if (words[i].length() == 0) continue; 
            if (v[0].find(words[i][0]) != v[0].end()) tag = 0;
            if (v[1].find(words[i][0]) != v[1].end()) tag = 1;
            if (v[2].find(words[i][0]) != v[2].end()) tag = 2;
            for (int j = 1; j < words[i].length(); j++) {
                if (v[tag].find(words[i][j]) == v[tag].end()) {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                result.push_back(words[i]);
        }
        return result;
    }
};

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.

题目大意：给一个string s和一个string字典d，找字典中的某个string，寻找s的子串（满足可以通过删除s中某些元素后得到该string），寻找满足条件的字符串中最长的一个，如果有多个长度相等的就返回字典序中最小的那个，如果一个都没有满足条件的string，就返回一个空字符串～
分析：遍历字典中的某一个字符串，设当前字符串的下标为index，对于当前字符串d[index]，使用两个指针i和j分别从头到尾遍历s和d[index]，随着i指针的增加，如果j指针所指元素和i指针所指元素相同就向后移动一位，当i指针都指完的时候，j如果也指完了说明满足条件，当前d[index]是s的子串，如果当前d[index]的长度比保存的result字符串长度长，就更新result，或者一样长但是字典序排列中d[index]比result小，也要更新result，最后返回result～

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        for (int index = 0; index < d.size(); index++) {
            int i, j;
            for (i = 0, j = 0; i < s.length() && j < d[index].length(); i++) {
                if (s[i] == d[index][j]) j++;
            }
            if (j == d[index].length() && (result.length() < d[index].length() || (result.length() == d[index].length() && result > d[index])))
                result = d[index];
        }
        return result;
    }
};
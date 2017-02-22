438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

分析：先将p字符串的所有字母的个数标记在hash数组中。设p的字符串长度为lenp，那么从字符串s的第一位开始分别找lenp长度的字串标记temphash，比较temphash是否等于hash，如果等于说明是anagram字符串，push_back到vector里面，最后返回vector

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result, hash(26, 0);
        int lenp = p.length(), lens = s.length();
        for(int i = 0; i < lenp; i++) {
            hash[p[i] - 'a']++;
        }
        for(int i = 0; i <= lens - lenp; i++) {
            vector<int> temphash(26, 0);
            for(int j = i; j < i + lenp; j++)
                temphash[s[j] - 'a']++;
            if(temphash == hash)
                result.push_back(i);
        }
        return result;
    }
};
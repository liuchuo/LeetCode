49. Group Anagrams
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

题目大意：给一组字符串，将这些字符串分组，按照同字母异序词为一组
分析：每一个s排序后的字符串为t，将s保存在以t为键的map中，这样同字母异序词即为一组。遍历map中的每一个vector<string>，将其保存在ans中，ans即为结果～

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for (auto s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        for (auto m : mp) {
            vector<string> temp(m.second.begin(), m.second.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
763. Partition Labels
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

题目大意：给出一个小写字母的字符串S. 我们想把这个字符串分成尽可能多的部分，这样每个字母最多只出现一个部分，并返回一个表示这些部分大小的整数列表。
分析：遍历字符串，找到S[i]在S中最后一次出现的位置标记为end，end位置是当前要切割的字串部分最短的结尾处，当i == end时候说明start～end可以组成一个最短部分串，将这个部分串的长度(end - start + 1)放入ans数组中，然后将start标记为下一个部分串的开始(end+1)，最后返回ans数组～

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        for (int i = 0, start = 0, end = 0; i < S.length(); i++) {
            end = max(end, (int)S.find_last_of(S[i]));
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
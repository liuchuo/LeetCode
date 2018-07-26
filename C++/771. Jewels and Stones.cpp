771. Jewels and Stones
You are given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

题目大意：J是珠宝，S是自己拥有的石头，判断自己拥有的石头中有多少个珠宝～
分析：将J中的所有字符在hash数组中标记为1，再遍历S，统计hash == 1的个数即为所求～

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0, hash[256] = {0};
        for (auto i : J) hash[i] = 1;
        for (auto i : S) if (hash[i]) ans++;
        return ans;
    }
};
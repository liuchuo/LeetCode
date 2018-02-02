443. String Compression
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has its own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.

分析：指针i指向修改内容的位置，指针j遍历整个数组chars，当下一个字符与当前字符不相同时，直接将该字符赋值到i处，然后i++，j++；否则若相同，k指向j所在位置，j继续向前出发遍历所有与k处相同的字符，则相同的个数为j-k，将j-k转化为字符串s，将s的每一个字符都赋值在i所在位置开始的chars中～最后直到j>=n时退出循环，此时i的值即为in-place后新数组中的个数～

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, n = chars.size();
        while (j < n) {
            if (j == n - 1 || chars[j] != chars[j + 1]) {
                chars[i++] = chars[j++];
            } else {
                chars[i++] = chars[j];
                int k = j;
                while (j < n && chars[j] == chars[k]) j++;
                string s = to_string(j - k);
                for (char c : s) chars[i++] = c;
            }
        }
        return i;
    }
};
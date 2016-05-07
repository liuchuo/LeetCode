168. Excel Sheet Column Title   
My Submissions QuestionEditorial Solution
Total Accepted: 59275 Total Submissions: 273414 Difficulty: Easy
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.

Subscribe to see which companies asked this question


把 A~Z 对应 0 ~ 25
满 26 进 1
只要看当前 n-1 的值是否 /26 != 0
如果是的 则 将 (n-1) % 26 + 'A' 存储在 s 之前
如果不是 则 退出 while 循环

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n) {
            s = (char)((n - 1) % 26 + 'A') + s;
            n = (n - 1) / 26;
        }
        return s;
    }
};
434. Number of Segments in a String 
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5

分析：一旦出现不是空格的s[i]并且他前一个不和他连续，那么就cnt++; 如果遇到是空格，重新将flag标记为0表示当前s[i]和下一个s[i]不连续～

class Solution {
public:
    int countSegments(string s) {
       int cnt = 0, flag = 0;
       for(int i = 0; i < s.length(); i++) {
           if(s[i] != ' ' && flag == 0) {
               cnt++;
               flag = 1;
           } else if(s[i] == ' ') {
               flag = 0;
           }
        }
        return cnt;
    }
};
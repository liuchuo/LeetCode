38. Count and Say
 My Submissions QuestionEditorial Solution
Total Accepted: 78289 Total Submissions: 271691 Difficulty: Easy
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Subscribe to see which companies asked this question


class Solution {
public:
    string countAndSay(int n) {
        string temp;
        string num;
        int cnt = 1;
        if(n == 1) {
            return "1";
        }
        if(n == 2) {
            return "11";
        }
        string a = "11";
        for(int i = 1; i <= n - 2; i++) {
            for(int j = 1; j < a.length(); j++) {
                if(a[j-1] == a[j]) {
                    cnt++;
                }
                if(a[j-1] != a[j]) {
                    while(cnt) {
                        num = (char)(cnt % 10 + '0') + num;
                        cnt = cnt / 10;
                    }
                    temp += num;
                    num = "";
                    temp += a[j-1];
                    cnt = 1;
                }
                if(j == a.length() - 1) {
                    while(cnt) {
                        num = (char)(cnt % 10 + '0') + num;
                        cnt = cnt / 10;
                    }
                    temp += num;
                    num = "";
                    temp += a[j];
                    cnt = 1;
                }
            }
            a = temp;
            temp = "";
        }
        return a;
    }
};
6. ZigZag Conversion   
My Submissions QuestionEditorial Solution
Total Accepted: 85965 Total Submissions: 358722 Difficulty: Easy
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
Subscribe to see which companies asked this question


class Solution {
public:
    string convert(string s, int numRows) {
        string t[numRows];
        string ans;
        int i = 0;
        while(i < s.length()) {
            for(int j = 0; j < numRows && i < s.length(); j++)
                t[j] += s[i++];
            for(int k = numRows - 2; k > 0 && i < s.length(); k--)
                t[k] += s[i++];
        }
        for(int j = 0; j < numRows; j++) {
            ans += t[j];
        }
        return ans;
    }
};
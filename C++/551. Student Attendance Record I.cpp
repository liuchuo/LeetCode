551. Student Attendance Record I
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False

分析：正则表达式匹配，如果出现三次连续的LLL或者两次AA则返回false

class Solution {
public:
    bool checkRecord(string s) {
        return !regex_match(s, regex(".*LLL.*|.*A.*A.*"));
    }
};
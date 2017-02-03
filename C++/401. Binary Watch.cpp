401. Binary Watch
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

分析：小时数h从0～11，分钟数m从0～59，把他们每一个转换为一个二进制整体，初始化为bitset，看bitset中1的个数是否为num，如果是就将h和m构成一个字符串加入到result字符串数组中，最后返回result～～

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                bitset<10> b(h << 6 | m);
                if(b.count() == num) {
                    string temp = to_string(h) + ":";
                    if(m < 10)
                        temp += "0";
                    temp += to_string(m);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
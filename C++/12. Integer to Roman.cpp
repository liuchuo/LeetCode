12. Integer to Roman
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

题目大意：将一个整数转化为罗马数字表示法～
分析：根据罗马数字的表示方法，我们直到罗马字符有"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"这几种，分别对应1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1。如果在这些数字之间的，比如3，那就重复3次写1：III。
所以只需要按照罗马数字表示的从大到小顺序，当num比a[i]大的时候，cnt = num / a[i],就将b[i]连接在result字符串后面cnt次。每一次循环将num取余a[i]，直到num<=0为止～

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string b[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int index = 0, cnt;
        while(num > 0) {
            cnt = num / a[index];
            while(cnt--)
                result += b[index];
            num = num % a[index];
            index++;
        }
        return result;
    }
};
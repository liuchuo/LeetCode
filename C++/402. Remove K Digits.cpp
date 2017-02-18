402. Remove K Digits
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

题目大意：给一个以字符串形式表示的非负整数，从字符串中移除k位，使得剩下的数字尽可能的小～
分析：将字符串中每一个元素放入栈中，如果当前要放入的元素比栈顶元素大，而且k > 0（还需要移除数字），则将栈顶元素弹出后再放入新的元素，因为前面的数字越小越好～等到所有数字都加入栈中后，如果k依旧>0，也就是说还有需要弹栈的数字，那就将最后几位移除，因为前面的数字肯定比后面的数字小～将栈中所有元素放入result字符串中，然后再用index判断第一个不为0的下标为多少，然后截取result为result.substr(index)去除了前导0，如果最后发现result为空则返回"0"，否则返回result～

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        stack<char> s;
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && !s.empty() && s.top() > num[i]) {
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        while (k > 0 && !s.empty()) {
            k--;
            s.pop();
        }
        while (!s.empty()) {
            result = s.top() + result;
            s.pop();
        }
        int index = 0;
        while (result[index] == '0') index++;
        result = result.substr(index);
        if (result == "") return "0";
        return result;
        
    }
};
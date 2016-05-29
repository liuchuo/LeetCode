7. Reverse Integer   
My Submissions QuestionEditorial Solution
Total Accepted: 136456 Total Submissions: 577747 Difficulty: Easy
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer’s last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.

Subscribe to see which companies asked this question


class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(s[0] == '-')
            std::reverse(s.begin() + 1, s.end());
        else
            std::reverse(s.begin(), s.end());
        long long int temp = stoll(s);
        if(temp > 2147483647 || temp < -2147483648)
            return 0;
        return (int)temp;
    }
};
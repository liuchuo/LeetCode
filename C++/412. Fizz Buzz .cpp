412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

分析：几个if else 语句分别对是否能被15整除、5整除、3整除进行赋值～

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for(int i = 0; i < n; i++) {
            if((i + 1) % 15 == 0)
                result[i] = "FizzBuzz";
            else if((i + 1) % 5 == 0)
                result[i] = "Buzz";
            else if((i + 1) % 3 == 0)
                result[i] = "Fizz";
            else
                result[i] = to_string(i + 1);
        }
        return result;
    }
};
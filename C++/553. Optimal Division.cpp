553. Optimal Division
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
since they don’t influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.

题目大意：给定一个正整数列表，相邻的整数将执行浮点除法。 例如[2,3,4] - > 2/3/4。但是，您可以在任何位置添加任意数量的括号以更改操作的优先级。您应该找到如何添加括号以获得最大结果，并以字符串格式返回相应的表达式，你的表达不应该包含多余的括号。
分析：要想得到最大的结果，只要使除数尽可能大，被除数尽可能小。被除过的数一定会变得更小，所以括号加在第一个数后面，括号内的数按从前到后顺序（不用添加冗余的括号）即可～

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = to_string(nums[0]);
        if (nums.size() == 1) return ans;
        if (nums.size() == 2) return ans + "/" + to_string(nums[1]);
        ans = ans + "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            ans = ans + "/" + to_string(nums[i]);
        }
        return ans + ")";
    }
};
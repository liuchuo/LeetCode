414. Third Maximum Number
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

分析：因为set会自动排序，所以每次将数字放入set，如果set里面容量超过三个就把最小的那个移除～
到最后如果set的大小不是3个，那就输出最大值，也就是*s.rbegin(), 如果set的大小是3个就输出*s.begin()即为第三大～

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            if(s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : * s.rbegin();
    }
};
453. Minimum Moves to Equal Array Elements
Contributors: amehrotra2610
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

分析：每次n-1个数都+1，最后所有数都相等，其实等价于每次将其中一个数-1，最后所有数都相等。
因为每次只能减一个数，那肯定是将除了最小数minn之外的其他所有数一次次减，直到他们等于都最小数minn。所以cnt就等于所有数与最小数之间的差距的和（因为每次只能减去一个数，且只能减去1，所以差为多少就要减去多少次～）
先求出数组的最小值minn，然后累加的所有数和minn之间的差即为所求～

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minn = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
            minn = min(minn, nums[i]);
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
            cnt += nums[i] - minn;
        return cnt;
    }
};

55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
题目解释：
从下标为0的地方开始，A[i]表示当前i处能够跳跃的最大长度。（也就是也就是i处最远能跳到下标i + nums[i]处。）判断能不能跳啊跳到最后一个下标的地方。
分析：设立distance为当处在i下标的时候，前面所能够达到的所有长度的最大值（因为是最大值，所以0~最大值的所有下标都可以遍历到），当i <= distance的所有下标都可以遍历，然后更新distance的值为distance = max(distance, i + nums[i]);
最后判断能够最远到达的distance是否够的到最后一个下标n-1，不能的话返回false，能的话返回true

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance = 0;
        for(int i = 0; i < nums.size() - 1 && i <= distance; i++) {
            distance = max(distance, i + nums[i]);
        }
        return distance >= (nums.size() - 1);
    }
};
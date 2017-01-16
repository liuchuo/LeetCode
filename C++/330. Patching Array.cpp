330. Patching Array
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.
题目大意：
给一个有序非负整数列nums和一个整数n，最少需要添加多少个数可以使得[1,n]间的每一个数都可以被数列中若干个数的和来表示。输出最小需要添加多少个数字。
分析：
假设[0,t)是暂时能够满足题意的区间，当t<=n的时候，对于每下一个nums[i]：
0.如果nums[i]比t小，那么[0,t)区间内的每一个数加上nums[i]后，区间就被扩展为[0,t+nums[i])了。
1.如果nums[i]比t大，那么必须要加入一个数才能满足扩展区间后的连续性。能加入的这个数当然是越大越好，但是不能超过t，因为超过t的话就会有t之后这个数之前的区间不满足。所以可以令t=t+t，这是它能扩展的最大区间了。此时用cnt计数，cnt+1表示加入了一个数（这个数是t）。
注意点：一开始全都用的int结果在测试用例Last executed input:[1,2,31,33] 2147483647 这个用例下面超时了
后来机智的想了一下发现是如果t当前的值很大又执行了t = t + t会溢出导致t变成了一个很小的值，然后再while肯定超时啦。
所以把int t = 1改为long long int类型就AC啦。啦啦啦。

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int len = nums.size();
        long long int t = 1;
        int cnt = 0;
        int i = 0;
        while(t <= n) {
            if(i < len && nums[i] <= t) {
                t = t + nums[i];
                i++;
            } else {
                t = t + t;
                cnt++;
            }
        }
        return cnt;
    }
};

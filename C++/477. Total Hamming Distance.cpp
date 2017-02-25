477. Total Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.

题目大意：两个数字的二进制表示中，相应的位不相同的个数即为这两个数的Hamming距离。给出一组数，计算他们每两对构成的Hamming距离的总和～
分析：遍历数组中所有数的相同某位，如果有cnt个1，n-cnt个0，则这一位能够构成的Hamming距离为cnt * (n - cnt)～所以从第0位开始一直计算到第32位，将所有位贡献的Hamming距离总和相加即可得到总的Hamming距离～

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0, n = nums.size();
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] >> i & 1 == 1)
                    cnt++;
            }
            result += cnt * (n - cnt);
        }
        return result;
    }
};
15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

题目大意：给一个整数数组，从中选三个元素abc，使a + b + c = 0，返回所有满足条件的abc集合，结果集合中的结果不能有重复～
分析：将sum数组排序，先确定nums[i]为第一个元素，为了避免重复，如果nums[i]和刚刚的nums[i-1]相同就跳过continue，然后begin指向i+1，end指向n-1，判断此时的sum是否等于0，如果等于0就将结果放入result数组中，且begin++，end--，为了避免重复，如果begin++后的元素依旧和刚才的元素相同，继续begin++，end同理～如果sum>0就将end--，如果sum<0就将begin++，最后返回result结果集～～

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 3) return result;
        sort(nums.begin(), nums.end());
        vector<int> temp(3);
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int begin = i + 1, end = n - 1;
            while(begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if(sum == 0) {
                    temp[0] = nums[i]; 
                    temp[1] = nums[begin]; 
                    temp[2] = nums[end];
                    result.push_back(temp);
                    begin++; 
                    end--;
                    while(begin < end && nums[begin] == nums[begin - 1]) begin++;
                    while(begin < end && nums[end] == nums[end + 1]) end--;
                } else if(sum > 0) {
                    end--;
                } else {
                    begin++;
                }
            }
        }
        return result;
    }
};
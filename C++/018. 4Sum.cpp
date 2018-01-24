18. 4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

题目大意：给一个整型数组，求abcd序列，使得a+b+c+d=target，返回所有不重复的abcd序列结果集合～
分析：对整型数组进行排序，先用i和j确定了前两个元素，然后用begin和end分别从j+1和最后一个元素n-1开始查找，根据sum的值移动begin和end指针，如果sum==target，就将结果放入结果集中；如果sum>target，将end向前移动一个，如果sum<target，就讲begin向后移动一个……为了避免重复，当i、j、begin、end和它们的前一个元素相同的时候，就跳过当前元素，直接移动到下一个～

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> result;
       int n = nums.size();
       if(n < 4) return result;
       sort(nums.begin(), nums.end());
       vector<int> temp(4);
       for(int i = 0; i < n - 3; i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;
           for(int j = i + 1; j < n - 2; j++) {
               if(j != i + 1 && nums[j] == nums[j-1]) continue;
               int begin = j + 1, end = n - 1;
               while(begin < end) {
                   int sum = nums[i] + nums[j] + nums[begin] + nums[end];
                   if(sum == target) {
                       temp[0] = nums[i];
                       temp[1] = nums[j];
                       temp[2] = nums[begin];
                       temp[3] = nums[end];
                       result.push_back(temp);
                       begin++;
                       end--;
                       while(begin < end && nums[begin] == nums[begin-1]) begin++;
                       while(begin < end && nums[end] == nums[end+1]) end--;
                   } else if(sum > target) {
                       end--;
                   } else {
                       begin++;
                   }
               }
           }
       }
       return result;
    }
};
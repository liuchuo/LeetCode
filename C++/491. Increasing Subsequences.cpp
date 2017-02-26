491. Increasing Subsequences
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

题目大意：给一个整型数组nums，寻找它的所有满足条件的子数组：每一个子数组内的元素都是递增的（允许包含重复元素，所以其实是不递减的）～以二维数组的方式返回～
分析：row为结果集的每一行的结果，深度优先搜索，两个参数：lastNum：表示当前row中最后一个元素的值，（即后面想要加进来的值必须大于等于lastNum），index：表示当前已加入row的元素中的最后一位的index，一开始lastNum = -101表示最小值，而index = -1。这样下一次就让i从index + 1开始遍历是否有比它大的或者等于它的元素，有就加入row并且dfs(nums[i], i)，最后记得将row的最后一个元素pop出来。当row中的元素大于等于2个的时候，就可以称为一个满足条件的结果，因为为了避免有重复元素，就将row插入一个集合中。最后遍历集合将所有一维数组都放入result二维数组中，返回result即可～

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        this->nums = nums;
        dfs(-101, -1);
        for (auto it = s.begin(); it != s.end(); it++)
            result.push_back(*it);
        return result;
    }
private:
    set<vector<int>> s;
    vector<int> nums, row;
    void dfs(int lastNum, int index) {
        if (row.size() >= 2) s.insert(row);
        if (index == nums.size()) return ;
        for (int i = index + 1; i < nums.size(); i++) {
            if (nums[i] >= lastNum) {
                row.push_back(nums[i]);
                dfs(nums[i], i);
                row.pop_back();
            }
        }
    }
};
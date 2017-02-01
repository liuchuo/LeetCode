220. Contains Duplicate III
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

题目大意：给一个整数数组，找到是否存在两个不同的下标i和j，使得nums[i]和nums[j]的差的绝对值不超过t并且i和j的差的绝对值不超过k～
分析：建立一个map，对应的是元素的值到元素的下标的映射。指针i将nums数组从头遍历到尾，j指针一开始指向0。i向右走的时候如果i和j之差大于k，且m中有nums[j]，就将nums[j]从m中移除，且j向前走一步～这样就保证了m中所有的元素满足第一个条件：i和j的差的绝对值不超过k～
接下来考虑nums[i]和nums[j]的差的绝对值不超过t，abs(num[i] - nums[j]) <= t 则 nums[j]的最小可能满足条件的值为>=nums[i] - t的，所以使用map中的lower_bound，寻找第一个大于等于nums[i] - t的地方，找到后标记为a，此时的a只是取到了可能满足的最小的a，但(a - nums[i])不一定满足，所以检验a是否存在于map中且是否abs(a->first - nums[i]) <= t。如果都满足说明可以return true～
如果到最后都没有能够return true，则return false～

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k && m[nums[j]] == j) m.erase(nums[j++]);
            auto a = m.lower_bound((long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
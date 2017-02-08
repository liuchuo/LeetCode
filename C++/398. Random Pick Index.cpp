398. Random Pick Index
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);

题目大意：给一个整数数组，里面可能有重复元素。给一个target，随机返回一个数组元素等于target的元素下标～
分析：将所有等于target的元素的下标存储在index数组中，然后根据rand() % index.size()的值随机从index中取一个值返回～

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        vector<int> index;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target)
                index.push_back(i);
        }
        return index[rand() % index.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
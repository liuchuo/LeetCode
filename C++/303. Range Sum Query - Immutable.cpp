303. Range Sum Query - Immutable   
My Submissions QuestionEditorial Solution
Total Accepted: 27644 Total Submissions: 113304 Difficulty: Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
Subscribe to see which companies asked this question


class NumArray {
private:
    vector<int> v;
public:
    NumArray(vector<int> &nums) {
        if(nums.size() == 0)
            return ;
        v.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            v.push_back(v[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i == 0)
            return v[j];
        return v[j] - v[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
189. Rotate Array 
My Submissions QuestionEditorial Solution
Total Accepted: 68454 Total Submissions: 325942 Difficulty: Easy
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for(int i = 0; i <= (n - 1 - k) / 2; i++) {
            swap(nums[i], nums[n - 1 - k - i]);
        }
        for(int i = n - k; i <= (n - 1 + n - k) / 2; i++) {
            swap(nums[i], nums[n - 1 + n - k - i]);
        }
        for(int i = 0; i <= (n - 1) / 2; i++) {
            swap(nums[i], nums[n - 1 - i]);
        }
    }
};
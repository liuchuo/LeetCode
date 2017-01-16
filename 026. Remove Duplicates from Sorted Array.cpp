26. Remove Duplicates from Sorted Array 
My Submissions QuestionEditorial Solution
Total Accepted: 123663 Total Submissions: 371141 Difficulty: Easy
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It does not matter what you leave beyond the new length.

//才明白这类题目的意思是 返回的是 length 的值 但是会检验你是不是删除了相同的数字使得符合条件。。然后他检验的时候输出的只是0~length-1的值。。后面的是否符合不用管。。。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int len = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};
88. Merge Sorted Array 
My Submissions QuestionEditorial Solution
Total Accepted: 96619 Total Submissions: 322174 Difficulty: Easy
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

Subscribe to see which companies asked this question


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int aindex = m - 1;
        int bindex = n - 1;
        while(aindex >= 0 && bindex >= 0) {
            if(nums1[aindex] > nums2[bindex]) {
                nums1[index--] = nums1[aindex--];
            } else {
                nums1[index--] = nums2[bindex--];
            }
        }
        while(bindex >= 0) {
            nums1[index--] = nums2[bindex--];
        }
    }
};
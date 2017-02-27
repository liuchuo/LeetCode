496. Next Greater Element I
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.

题目大意：给两个数组findNums和nums，返回一个和findNums等长的数组，其返回的内容为：对于findNums[i]，返回的result[i]为nums[i]数组中，findNums[i]的后面的元素中第一个比findNums[i]大的元素。如果不存在这样的元素就写-1。其中findNums数组是nums数组的子数组～
分析：使用栈，从后往前遍历nums[i]，每当栈不为空的时候，一直出栈直到遇到比nums[i]大的数字停止。设立一个map<int, int> m，存储nums中每一个元素以及它对应的下一个最大元素构成的映射。如果停止后栈为空就将m[nums[i]]标记为-1，否则就写栈的栈顶元素～
最后将findNums中出现的每一个元素对应的map的值放入result数组中返回～

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        stack<int> s;
        map<int, int> m;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) 
                s.pop();
            m[nums[i]] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        for (int i = 0; i < findNums.size(); i++)
            result.push_back(m[findNums[i]]);
        return result;
    }
};
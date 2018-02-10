532. K-diff Pairs in an Array
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array wont exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].

题目大意：给定一个整数和一个整数k的数组，你需要找到数组中唯一的k-diff对的个数。 这里k-diff对被定义为一个整数对（i，j），其中i和j都是数组中的数字，它们的绝对差值是k。
分析：对于当前遍历的nums[i]，在它前面找是否存在满足与它相差k的数字，如果找到了就将这对数字(i, j)中较大的一个数字放到set里，然后将这个数在map中标记为true表示存在这个数字等待它的后面的数字判断它是否存在（这样可以避免重复，也就是说每个数字只在它前面找是否有符合条件的数字），最后返回set的大小～

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, bool> m;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i] - k]) s.insert(nums[i]);
            if (m[nums[i] + k]) s.insert(nums[i] + k);
            m[nums[i]] = true;
        }
        return s.size();
    }
};
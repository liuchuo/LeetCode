448. Find All Numbers Disappeared in an Array 
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

分析：hash[i]用来标记i是否在nums数组中出现过。然后将没有出现过的放入result数组中，返回result数组～～～

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        vector<bool> hash(nums.size() + 1, false);
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = true;
        }
        for(int i = 1; i < hash.size(); i++) {
            if(hash[i] == false)
                result.push_back(i);
        }
        return result;
    }
};
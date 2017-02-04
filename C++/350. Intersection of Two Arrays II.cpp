350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

分析：将nums1的每一个数字以及对应数字的个数存储在map里面，遍历nums2中的所有元素，如果当前元素在map中存在，就把它放入result数组中，并将其数量-1。最终返回result即为所求交集～

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> m;
        for(int i = 0; i < nums1.size(); i++)
            m[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++) {
            if(m[nums2[i]] != 0) {
                m[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};
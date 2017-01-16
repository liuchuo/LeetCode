349. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        for(int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(s1.find(nums2[i]) != s1.end()) {
                s2.insert(nums2[i]);
            }
        }
        vector<int> v;
        for(set<int>::iterator it = s2.begin(); it != s2.end(); it++) {
            v.push_back(*it);
        }
        return v;
    }
};
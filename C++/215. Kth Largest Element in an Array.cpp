215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

分析：一开始用set，后来发现是“not the kth distinct element”，所以说不能用set，set里面元素必须是不相同的，所以这里用multiset就能解决。
因为multiset会自动排序，所以每次将数字放入multiset，如果集合里面容量超过k个就把最小的那个移除～
到最后输出*s.begin()即为第k大～

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            if(s.size() > k)
                s.erase(s.begin());
        }
        return *s.begin();
    }
};
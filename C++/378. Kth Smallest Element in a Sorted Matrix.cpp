378. Kth Smallest Element in a Sorted Matrix 
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

分析：使用multiset，因为是求第k小的，而且允许相同的元素，所以使用可以存储相同元素的multiset。当multiset里面的元素大于k个的时候，删除集合中最大的那个（即最后一个元素，也就是s.end()的前一个），最后输出最后一个元素即可～即 *s.rbegin()~~~

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int> s;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                s.insert(matrix[i][j]);
                if(s.size() > k)
                    s.erase(--s.end());
            }
        }
        return *s.rbegin();
    }
};
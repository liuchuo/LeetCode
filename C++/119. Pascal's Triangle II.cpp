119. Pascal's Triangle II 
My Submissions QuestionEditorial Solution
Total Accepted: 72147 Total Submissions: 224801 Difficulty: Easy
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        v[0] = 1;
        for(int i = 1; i <= rowIndex; i++) {
            v[i] = (long long int)v[i-1] *(long long int)(rowIndex-i+1) / i;
        }
        return v;
    }
};
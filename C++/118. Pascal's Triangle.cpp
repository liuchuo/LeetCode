118. Pascal's Triangle 
My Submissions QuestionEditorial Solution
Total Accepted: 80029 Total Submissions: 241495 Difficulty: Easy
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Subscribe to see which companies asked this question



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        if(numRows == 0)
            return v;
        for(int i = 0; i < numRows; i++) {
            v[i].resize(i + 1);
        }
        v[0][0] = 1;
        if(numRows == 1)
            return v;
        v[1][0] = 1;
        v[1][1] = 1;
        for(int i = 2; i < numRows; i++) {
            v[i][0] = 1;
            v[i][i] = 1;
        }
        for(int i = 2; i < numRows; i++) {
            for(int j = 1; j < i; j++) {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        return v;
    }
};
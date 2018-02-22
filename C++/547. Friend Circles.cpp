547. Friend Circles
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.

题目大意：班上有N个学生。 有些是朋友，有些则不是。 他们的友谊本质上是传递性的。 例如，如果A是B的直接朋友，B是C的直接朋友，那么A是C的间接朋友。我们定义了一个朋友圈是一群直接或间接的朋友。给定N * N矩阵M代表班级中学生之间的朋友关系。 如果M[i][j] = 1，那么第i和第j个学生是彼此直接的朋友，否则不是，输出所有学生中的朋友圈的总数
分析：用并查集，cnt一开始为n，每个人的父亲也都是自己，将每一对朋友的父亲结点找到，如果他们的父亲结点不是同一个，那么就合并为一个集合，并将cnt-1，最后输出cnt

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), cnt = M.size();
        father.resize(n);
        for (int i = 0; i < n; i++) father[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1) {
                    int faA = findFather(i);
                    int faB = findFather(j);
                    if (faA != faB) {
                        father[faA] = father[faB];
                        cnt--;
                    }
                }
                
            }
        }
        return cnt;
    }
private:
    vector<int> father;
    int findFather(int x) {
        return x == father[x] ? x : findFather(father[x]);
    }
};
526. Beautiful Arrangement
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.

题目大意：N个数1～N，求它有多少种排列方式，满足：对于每一位，i位上的数字能被i整除，或者i能被i位上的数字整除～
分析：深度优先搜索，从N开始一直到0，用visit标记当前元素是否访问过，当当前下标为1的时候表示当前深度优先的一条路径满足条件，result+1，否则遍历visit数组看有没有没被访问过的元素，如果满足(i % index == 0 || index % i == 0)就标记为已经访问过，然后继续向下遍历dfs(index-1)～最后返回result的结果～

class Solution {
public:
    int countArrangement(int N) {
        visit.resize(N+1);
        dfs(N);
        return result;
    }
private:
    int result = 0;
    vector<bool> visit;
    void dfs(int index) {
        if (index == 1) {
            result++;
            return;
        }
        for (int i = 1; i < visit.size(); i++) {
            if (visit[i] == false && (i % index == 0 || index % i == 0)) {
                visit[i] = true;
                dfs(index-1);
                visit[i] = false;
            }
        }
    }
};
447. Number of Boomerangs 
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]
Output:
2
Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

分析：map(m[i] = j)用来存储点与点之间距离（其实是距离的平方，不影响结果）为i的个数j。对于某一点，距离它为i的个数若为j个，则能够构成的i，j，k这样的组数是j * (j - 1)个。每次累计得到的总结果即为所求～

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int cnt = 0;
        for(int i = 0; i < points.size(); i++) {
            map<int, int> m;
            int x1 = points[i].first, y1 = points[i].second;
            for(int j = 0; j < points.size(); j++) {
                if(j == i) continue;
                int x2 = points[j].first, y2 = points[j].second;
                int dis = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
                m[dis]++;
            }
            for(auto it = m.begin(); it != m.end(); it++) {
                cnt += it->second * (it->second - 1);
            }
        }
        return cnt;
    }
};
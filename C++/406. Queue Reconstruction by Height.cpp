406. Queue Reconstruction by Height
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

题目大意：给一组序列(h, k), h表示身高，k表示在当前人的前面有k个人比他高，求满足这样的排队序列～
分析：先将所有人按照身高h排序，如果他们的身高h相同就按照k从小到大排序～接下来就可以构建result数组了，从排序好的序列第一个数开始一直遍历到最后一个，依次把它插入到result数组的第k位，因为对于当前这个人，他说了比他高的人是k个，而整个数组按照身高排序了，所以前面的所有人都是比他高的，排他的队伍的时候只需要排到第k位就能满足他前面比他高的人是k个～这样将所有人都插入后得到的result即为所求队伍的顺序～～

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        if(people.size() == 0)
            return result;
        auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            else
                return p1.first > p2.first;
        };
        sort(people.begin(), people.end(), cmp);
        for(auto it : people) {
            result.insert(result.begin() + it.second, it);
        }
        return result;
    }
};
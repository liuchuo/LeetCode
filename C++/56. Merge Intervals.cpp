56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

题目大意：给一组区间，合并他们所有的重叠区间
分析：先对所有区间按左区间从小到大排序，排序后将第一个区间放入ans结果数组中，遍历原数组，如果当前ans数组的最后一个区间的end小于intervals[i]的start，说明与其没有交集，那么就将这个intervals[i]放入结果数组中。否则说明有交集，就将当前ans数组的最后一个区间的end更新为ans.back().end和intervals[i].end()中较大的那一个，最后返回ans数组即为所求～注意如果intervals中不含元素要返回空集


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if(ans.back().end < intervals[i].start) 
                ans.push_back(intervals[i]);
            else
                ans.back().end = max(ans.back().end, intervals[i].end);
        }
        return ans;
    }
};
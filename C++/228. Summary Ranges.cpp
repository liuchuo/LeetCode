228. Summary Ranges
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

分析：判断当前nums[i]与nums[i-1]是否是相连，如果是相连就令flag = 1，如果不相连了就将前面的结果放入result数组中。最后for循环之外还要记得把temp字符串再压入数组result中，因为当前最后一次的temp还未被处理。最后返回结果～

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0)
            return result;
        string temp = "";
        int flag = 0;
        temp += to_string(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1] + 1 && flag == 1) {
                flag = 0;
                temp += "->" + to_string(nums[i-1]);
                result.push_back(temp);
                temp = "" + to_string(nums[i]);
            } else if(nums[i] != nums[i-1] + 1) {
                result.push_back(temp);
                temp = "" + to_string(nums[i]);
            } else {
                flag = 1;
            }
        }
        if(flag == 1) {
            temp += "->" + to_string(nums[nums.size() - 1]);
        }
        result.push_back(temp);
        return result;
    }
};


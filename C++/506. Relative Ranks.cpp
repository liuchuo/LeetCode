506. Relative Ranks
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.

题目大意：给一个数组，为几个运动员的分数，返回他们的排名，如果前三名应该为"Gold Medal", "Silver Medal", "Bronze Medal"，否则是数字名次，保证所有的分数不重复～
分析：拷贝一个相同的数组arr，然后排序，从nums[i]中寻找与arr[j]相同的分数，名次即为j+1。如果j为0，1，2则需要特殊处理～

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> arr = nums;
        auto cmp = [](int a, int b) {return a > b;};
        sort(arr.begin(), arr.end(), cmp);
        vector<string> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == arr[j]) {
                    switch(j) {
                        case 0: result[i] = "Gold Medal"; break;
                        case 1: result[i] = "Silver Medal"; break;
                        case 2: result[i] = "Bronze Medal"; break;
                        default: result[i] = to_string(j + 1); break;
                    }
                    break;
                }
            }
        }
        return result;
    }
};
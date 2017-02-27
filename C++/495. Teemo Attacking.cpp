495. Teemo Attacking
In LLP world, there is a hero called Teemo and his attacking can make his enemy Ashe be in poisoned condition. Now, given the Teemo's attacking ascending time series towards Ashe and the poisoning time duration per Teemo's attacking, you need to output the total time that Ashe is in poisoned condition.

You may assume that Teemo attacks at the very beginning of a specific time point, and makes Ashe be in poisoned condition immediately.

Example 1:
Input: [1,4], 2
Output: 4
Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately. 
This poisoned status will last 2 seconds until the end of time point 2. 
And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds. 
So you finally need to output 4.
Example 2:
Input: [1,2], 2
Output: 3
Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned. 
This poisoned status will last 2 seconds until the end of time point 2. 
However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status. 
Since the poisoned status won't add up together, though the second poisoning attack will still work at time point 2, it will stop at the end of time point 3. 
So you finally need to output 3.
Note:
You may assume the length of given time series array won't exceed 10000.
You may assume the numbers in the Teemo's attacking time series and his poisoning time duration per attacking are non-negative integers, which won't exceed 10,000,000.

题目大意：给一个数组和一个数字，数组中元素是升序的，每一个元素代表释放毒气的时间点，数字duration表示释放毒气能够中毒的时间，比如时间点1开始攻击，持续2秒，则在第2秒结束后才会恢复不中毒～如果前一次中毒ing而后一次提早又被攻击，那就是后一次攻击后+持续时间才会恢复不中毒～现在要求这个人一共中毒了多少秒～
分析：oldEnd表示这一次攻击之前的攻击导致的最晚中毒结束时间，首先初值是-1表示刚开始的时候不是中毒的（也就是中毒结束时间是-1，不能是0因为有一个测试用例时间点是从0开始的。。），遍历数组，对于每一个timeSeries[i], 这次攻击导致的中毒结束时间是newEnd = timeSeries[i] + duration - 1，如果新的结束时间比之前的结束时间长，就取duration, newEnd - oldEnd)中较小的一个，因为如果oldEnd早就结束了，那就是duration让他中毒了duration秒，如果oldEnd结束的比较晚，晚于这一次攻击开始的时间，那么累计的中毒事件就应该是newEnd - oldEnd也就是新的攻击造成的结束时间减去旧的攻击结束时间～并且让oldEnd更新为newEnd的这个较大的值～如果新的结束时间比之前的结束时间短，那么不需要累加，反正这次攻击不攻击都没什么用因为反正是中毒ing...最后返回result累加的结果即可～

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0, oldEnd = -1;
        for (int i = 0; i < timeSeries.size(); i++) {
            int newEnd = timeSeries[i] + duration - 1;
            if (newEnd > oldEnd) {
                result += min(duration, newEnd - oldEnd);
                oldEnd = newEnd;
            }
        }
        return result;
    }
};
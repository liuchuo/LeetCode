575. Distribute Candies
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].

题目大意：给定一个长度为偶数的整型数组，这个数组中的不同数字表示不同类型的糖果。 每个数字表示相应种类的一个糖果。你需要把这些糖果平均分配给弟弟和姐姐。 返回姐姐可以获得的最大数量的糖果种类。
分析：放入unorder_set的集合中，集合中元素的个数就是糖果的种类，如果种类大于一半则返回一半的值，否则返回集合内的元素种类即可～

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for (int i = 0; i < candies.size(); i++) s.insert(candies[i]);
        return min(s.size(), candies.size() / 2);
    }
};
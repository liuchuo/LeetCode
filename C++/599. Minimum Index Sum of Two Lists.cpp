599. Minimum Index Sum of Two Lists
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.

题目大意：假设安迪和多丽丝想选择一家餐厅吃饭，他们有一串最喜欢的餐厅名单。你需要帮助他们用最小的指数总和找到他们的共同兴趣。 如果答案有多个则没有顺序要求地返回所有答案在string数组中
分析：当i+j比minSum小时将数组清空，minSum赋值为i+j，list1[i]放入ans数组中

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int minSum = 2000;
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i] == list2[j] && minSum > i + j) {
                    ans.clear();
                    ans.push_back(list1[i]);
                    minSum = i + j;
                } else if (list1[i] == list2[j] && minSum == i + j) {
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};
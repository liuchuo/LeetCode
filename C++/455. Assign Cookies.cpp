455. Assign Cookies
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

分析：先将g数组和s数组从小到大排序～ i指针遍历g数组，j指针遍历s数组，如果当前g[i] <= s[j]，也就是当前糖果j能够分给当前小朋友i，那就分配，并且将i指针指向下一个小朋友，cnt同时也要累加一个～如果当前糖果不能分配给当前小朋友，说明糖果j不能分给任何人了，因为没有比小朋友i需要的还要少的小朋友了（i后面的数都比i大）。所以无论是否分配，都把j向后移动一次～这样能保证需求量小的所有小朋友都分配得到能够分配的糖果，此时的cnt也是所求的贪心最大值～避免了大材小用（大糖果分配给需求量小的小朋友）的情况～

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0, i = 0, j = 0;
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
475. Heaters
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters‘ warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.

题目大意：给出房子的坐标和供暖器的坐标，求供暖器的最小供热半径是多少才能满足让所有房子都暖和。
分析：先将houses和heaters排序，计算每一个house左右的供暖器的距离最小的那个值，然后将所有的这些最小值中取最大的值。
因为houses和heaters都是排序好的，所以heater[j]与houses[i]的距离应该越来越小，如果突然间变大了，说明不是最小值了，就break掉。这样就能得知最小值。

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int startindex = 0, maxn = 0;
        for(int i = 0; i < houses.size(); i++) {
            int tempmin = INT_MAX;
            for(int j = startindex; j < heaters.size(); j++) {
                if(abs(heaters[j] - houses[i]) <= tempmin) {
                    tempmin = abs(heaters[j] - houses[i]);
                    startindex = j;
                } else {
                    break;
                }
            }
            maxn = max(maxn, tempmin);
        }
        return maxn;
    }
};
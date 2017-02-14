365. Water and Jug Problem
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False

题目大意：给两个容量为x和y升的容器，和无限多的水。你需要确定是否可能用x和y量出z升的水，z升的水必须用一个或者两个容器盛装。
分析：首先x和y的总容量一定要大于z。其次如果z == 0则直接return true; 最后需要满足z必须是x和y的最大公约数的倍数～最大公约数采用辗转相除法求得～

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
private:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
};
464. Can I Win
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

题目大意：两个人玩游戏，从1～maxChoosableInteger中任选一个数字，第一个人先选，第二个人后选，每个人选过的数字就不能再选了～两个人谁先加起来总和超过desiredTotal谁就赢，问给出数字，第一个人能否赢得比赛～
分析：两个特殊情况：1.如果能够选的最大数字大于等于desiredTotal，第一个人又不傻肯定选最大的值～那样他就赢啦～即：
if(maxn >= desiredTotal) return true;
2.如果所有能够选的数字的总和都小于desiredTotal，再怎么选两个人都不可能赢，所以肯定输～：
总和就是首项加末项的和乘以项数除以2～：if((1 + maxn) * maxn / 2 < desiredTotal) return false;
然后建立一个canWin函数，需要用visited标记某个数字是否被选过～因为可选的数字最大不超过20，则可以用一个整型数组标记，因为整型有32位～如果1被选过就把第1位（不是第0位哦～当然也可以从0开始啦～）标记为1，如果2被选过就把第2位标记为1～这样保证所有数字不重复～
所以传入两个值，一个是想要达到（或者说超过，也就是大于等于啦）的目标数字target，另一个是visited数字标记哪些数字被选过了～
用map标记当前情况在map表中是否存在，存在的话结果保存在map里面～如果我们发现这个visited也就是这个数字选择的情况已经被保存过了，就直接返回在map里面保存的结果～
遍历i从1到maxn（maxn是可以选择的最大值，即maxChoosableInteger），表示考虑选择i的情况，用mask = 1 << i，如果mask和visited进行与运算，如果等于0说明当前的visited没有被访问过，就可以考虑这个i的情况，如果要选的这个i大于target，不傻的这个人就会选择i因为肯定能赢啦～还有种情况自己能赢，就是对方输了，即：canWin(target - i, mask | visited) == false，（mask | visited表示把i那位也标记为1～）这个时候把visited情况存起来并且return true，表示赢了～如果所有数字都遍历完还是没有return true，那就最后return false～return false之前不要忘记把当前状态存储起来～也就是m[visited] = false; ～
注意：调了两个小时的bug后来才发现！(mask & visited) == 0一开始忘记加括号了，写成了mask & visited == 0，但是&运算符比==优先级低，所以==会先运算。。所以就gg了～注意注意～号外号外～

class Solution {
private:
    int maxn;
    map<int, bool> m;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxn = maxChoosableInteger;
        if(maxn >= desiredTotal) return true;
        if((1 + maxn) * maxn / 2 < desiredTotal) return false;
        return canWin(desiredTotal, 0);
    }
    bool canWin(int target, int visited) {
        if(m.find(visited) != m.end()) return m[visited];
        for(int i = 1; i <= maxn; i++) {
            int mask = (1 << i);
            if((mask & visited) == 0 && (i >= target || canWin(target - i, mask | visited) == false)) {
                m[visited] = true;
                return true;
            }
        }
        m[visited] = false;
        return false;
    }
};
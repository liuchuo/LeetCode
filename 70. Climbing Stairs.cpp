70. Climbing Stairs 
My Submissions QuestionEditorial Solution
Total Accepted: 103040 Total Submissions: 281923 Difficulty: Easy
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Subscribe to see which companies asked this question

class Solution {
public:
    int climbStairs(int n) {
        int *a = new int [n + 1];
        a[0] = 1;
        a[1] = 1;
        for(int i = 2; i <= n; i++) {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
    }
};

//一开始我写了个Fibonacci递归，在n = 44 时候超时了
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

//最最一开始我用的最原始的递归， 在 n=38的时候超时了
class Solution {
public:
    int ans = 0;
    int climbStairs(int n) {
        if(n == 0) {
            ans++;
            return ans;
        }
        if(n >= 1) {
            climbStairs(n - 1);
        }
        if(n >= 2) {
            climbStairs(n - 2);
        }
    }
};
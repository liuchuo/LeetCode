307. Range Sum Query - Mutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

题目大意：给一个整型数组，当调用sumRange(i, j)的时候返回i～j之间的元素的总和，当调用update(i, val)的时候将nums[i]的值更新为val
分析：本来想用sum[]数组标记和，然后更新sum[]直接返回的，结果还是意料之中的超时了。。用树状数组的方法可以解决～
解释：树状数组本质上是按照二分对数组进行分组，维护和查询都是O(lgn)的复杂度
树状数组与线段树：树状数组和线段树很像，但能用树状数组解决的问题，基本上都能用线段树解决，而线段树能解决的树状数组不一定能解决。相比较而言，树状数组效率要高很多～
关于lowbit：
lowbit = x & (-x), lowbit(x)也可以理解为能整除x的最大的2的幂次
如果要求[x, y]之内的数的和，可以转换成getsum(y) – getsum(x – 1)来解决～
树状数组模版：
#define lowbit(i) ((i) & (-i))
int getsum(int x) {
  int sum = 0;
  for(int i = x; i >= 1; i -= lowbit(x))
    sum += c[i];
  return sum;
}
void update(int x, int v) {
  for(int i = x; i <= n; i += lowbit(x))
    c[i] += v;
}
所以这道题的AC代码如下～：

class NumArray {
public:
    NumArray(vector<int> nums) {
       size = nums.size();
       num = vector<int>(size + 1, 0);
       sum = vector<int>(size + 1, 0);
       for(int i = 0;i < size; i++)
           update(i, nums[i]); 
    }
    
    void update(int i, int val) {
        int old = num[i+1];
        for(int j = i + 1;j <= size; j += (j & (-j)))
            sum[j] = sum[j] - old + val;
        num[i+1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
private:
    int getSum(int k) {
        int result = 0;
        for(int i = k;i > 0;i -= (i & (-i)))
            result += sum[i];
        return result;
    }
    int size;
    vector<int> sum, num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
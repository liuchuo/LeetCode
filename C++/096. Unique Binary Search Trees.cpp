96. Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

二分查找树的定义是，左子树节点均小于root，右子树节点均大于root~~~
所以可以用递推的方法，把v[i]表示i个数能够构成的二叉搜索树的个数~~
初始化边界值是 v[0]=1,v[1]=1,v[2]=2~~~
当i>=3的时候，若以j为root结点，v[j-1]等于root结点左边的j-1个结点能构成的BST个数~~
v[i-j]等于root结点右边i-j个结点能构成的BST个数~//j+1~i的种数和0~i-j的种数一样。。所以就是v[i-j]~
所以v[j-1] * v[i-j]等于以j为root结点能构成的BST种数~~~
j可以取1~i中的任意一个值，把这些所有计算出来的总数相加就是v[i]的值~~~~
所以 for(int j = 1; j <= i; j++) {
v[i] += v[j-1] * v[i-j];
}
最后返回的值是v[n]的值，表示1~n能组成的BST的个数~~~~


class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n+1);
        v[0] = 1;
        for(int i = 1; i <= n; i++) {
            v[i] = 0;
            if(i <= 2) {
                v[i] = i;
            } else {
                for(int j = 1; j <= i; j++) {
                    v[i] += v[j-1] * v[i-j];
                }
            }
        }
        return v[n];
    }
};
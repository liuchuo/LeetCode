769. Max Chunks To Make Sorted
Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn’t sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].

题目大意：给0～arr.length-1的一个排列，我们将数组拆分成一些“块”（分区），并对每个块进行单独排序。 连接它们之后，结果等于排序后的数组。问最多能够分成多少个分区（块）
分析：因为数组的排序后正确顺序应该是arr[i]处的数是i。所以，遍历数组，每次将最大的那个值标记为maxn，maxn必须在i处才能满足对0～i数字排序后能够恰好是正确的位置，此时ans+1，表示前面的可以组为一个“块”，最后ans即为所求的值～
再解释详细些：maxn是第0～i个数字中的最大值，遍历的过程中如果maxn==i，就保证了前面i-1个数字必然都比maxn小（因为maxn是0～i中的最大值），则第0～i个数字必然能排列成正确顺序，以此类推，找到下一个满足maxn==i的地方（记为j），则i+1～j又能分为一个块...直到遍历到最后一个数为止得到答案～

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        for (int i = 0, maxn = 0; i < arr.size(); i++) {
            maxn = max(arr[i], maxn);
            if (maxn == i) ans++;
        }
        return ans;
    }
};
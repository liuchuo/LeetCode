384. Shuffle an Array
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

题目大意：实现洗牌算法。给定一个没有重复元素的数组，写shuffle和set函数，shuffle函数要求对nums数组进行洗牌然后返回，set函数要求返回原来的nums数组～
分析：设立两个数组nums和origin，如果set就返回不会更改的origin数组，如果要洗牌，从nums的最后一位开始，设index为0～n-1中的一个随机数，产生后将index与最后一位元素进行交换，这样最后一位就算敲定了，然后再往前一位，假设当前位的下标是k，那就产生0～k之间的一个随机数，然后交换，以此类推，rand() % (i + 1)表示生成0～i中的一个随机数～直到第一位为止～

class Solution {
private:
    vector<int> nums;
    vector<int> origin;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        this->origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--) {
            int index = rand() % (i + 1);
            swap(nums[i], nums[index]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
503. Next Greater Element II
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.

题目大意：给一个循环数组，返回一个等长的数组，数组中的每一个元素是：它后面的第一个大于它的元素（如果后面没有就循环一遍到最前面找，直到循环了一圈为止），如果不存在这样的数，就返回-1～
分析：首先建立一个等长的result数组，起始都是-1。和Next Greater Element I类似，不过这个题目要两个循环解决，第一个循环i从0～n-1，对于每一个nums[i]，把他们的下标index都放入栈中。但是在放入栈之前需要做这样的事情：比较栈顶元素和nums[i]，如果恰好比nums[i]小，说明nums[i]就是它的第一大元素，就将result[s.top()]的值变为nums[i]，这样栈中的下标始终是它的后面找不到比他大的元素的下标，也就是说栈中在遍历一遍后剩下的元素的值都是递减次序的～
开始第二次循环，依旧i从0～n-1，但是这次不需要push入栈了，只需要处理栈中剩下的元素，对于nums[i]，如果栈顶元素和nums[i]比较，恰好nums[i]大，说明nums[i]就是他们这些没在后面找到最大元素的最大元素，出栈，result[s.top()] = nums[i]。这样所有遍历完毕后栈中只会剩下唯一一个元素，也就是该数组中最大的元素，它的result依旧是-1，其他的都已经更新完毕。也就是说，第一次遍历是为了找它后面比它大的元素，而第二次遍历是为了找前面比他大的元素～

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                result[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                result[s.top()] = nums[i];
                s.pop();
            }
        }
        return result;
    }
};
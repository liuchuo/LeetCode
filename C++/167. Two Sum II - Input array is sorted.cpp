167. Two Sum II - Input array is sorted
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

分析：每个数遍历找他的后面是否存在与它相加等于target的数，如果存在就放入result数组中。

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = i + 1; j < numbers.size(); j++) {
                if(numbers[i] + numbers[j] == target) {
                    result[0] = i + 1;
                    result[1] = j + 1;
                    break;
                } else if(numbers[i] + numbers[j] > target) {
                    break;
                }
            }
            if(result[0] != 0)
                break;
        }
        return result;
    }
};
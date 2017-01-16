66. Plus One 
My Submissions QuestionEditorial Solution
Total Accepted: 94851 Total Submissions: 284653 Difficulty: Easy
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Subscribe to see which companies asked this question



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            for(int i = digits.size() - 1; i >= 0; i--) {
                if(digits[i] != 9) {
                    digits[i] = digits[i] + 1;
                    return digits;
                } else {
                    digits[i] = 0;
                }
            }
            digits.insert(digits.begin(), 1);
            
            return digits;
            
    }
};
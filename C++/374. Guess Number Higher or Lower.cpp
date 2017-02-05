374. Guess Number Higher or Lower
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.

分析：二分查找法解决，不过要注意mid = low + (high - low) / 2 不要写成 mid = (low + high) / 2 ，后者超过了Int类型的最大值，相加变成负数，会导致超时

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int temp = guess(mid);
            if(temp == 1)
                low = mid + 1;
            else if(temp == -1)
                high = mid - 1;
            else
                return mid;
        }
    }
};
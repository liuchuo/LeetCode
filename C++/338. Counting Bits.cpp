338. Counting Bits 
My Submissions QuestionEditorial Solution
Total Accepted: 12949 Total Submissions: 23248 Difficulty: Medium
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1’s in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.


update v3.0:
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        v[0] = 0;
        for(int i = 1; i < num + 1; i++) {
            v[i] = v[i >> 1] + i % 2;
        }
        return v;
    }
};


update v2.0:
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        v[0] = 0;
        v[1] = 1;
        v[2] = 1;
        v[3] = 2;
        for(int i = 4; i < num + 1; i = i * 2) {
            for(int j = i; j < i + i/2 && j < num + 1; j++) {
                v[j] = v[j - i/2];
            }
            for(int j = i + i/2; j < i * 2 && j < num + 1; j++) {
                int temp = j;
                int cnt = 0;
                while(temp) {
                    cnt = cnt + temp % 2;
                    temp = temp/2;
                }
                v[j] = cnt;
            }
        }
        return v;
    }
};


version v1.0
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        for(int i = 0; i <= num; i++) {
            int temp = i;
            int cnt = 0;
            while(temp) {
                cnt = cnt + temp % 2;
                temp = temp / 2;
            }
            v[i] = cnt;
        }
        return v;
    }
};
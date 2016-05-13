28. Implement strStr()
My Submissions QuestionEditorial Solution
Total Accepted: 103132 Total Submissions: 415629 Difficulty: Easy
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Subscribe to see which companies asked this question


class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len2 == 0)
            return 0;
        for(int i = 0; i <= len1 - len2; i++) {
            for(int j = 0; j < len2 && needle[j] == haystack[i + j]; j++) {
                if(j == len2 - 1)
                    return i;
            }
        }
        return -1;
    }
};
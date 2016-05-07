165. Compare Version Numbers   
My Submissions QuestionEditorial Solution
Total Accepted: 51605 Total Submissions: 295830 Difficulty: Easy
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question


class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(!version1.empty() || !version2.empty()) {
            int ver1 = version1.empty() ? 0 : stoi(version1);
            int ver2 = version2.empty() ? 0 : stoi(version2);
            if(ver1 > ver2) {
                return 1;
            } else if(ver1 < ver2) {
                return -1;
            } else {
                int pos1 = version1.find('.');
                int pos2 = version2.find('.');
                version1 = (pos1 == string::npos) ? "" : version1.substr(pos1 + 1);
                version2 = (pos2 == string::npos) ? "" : version2.substr(pos2 + 1);
            }
        }
        return 0;
    }
};
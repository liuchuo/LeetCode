299. Bulls and Cows
 My Submissions QuestionEditorial Solution
Total Accepted: 25602 Total Submissions: 87120 Difficulty: Easy
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Subscribe to see which companies asked this question


class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int s[10], g[10];
        memset(s, 0, sizeof(int) * 10);
        memset(g, 0, sizeof(int) * 10);
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                bull++;
            } else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        
        for(int i = 0; i < 10; i++) {
            if(s[i] >= g[i]) {
                cow = cow + g[i];
            } else {
                cow = cow + s[i];
            }
        }
        
        string b = "";
        if(bull == 0)
            b = "0";
        while(bull) {
            char temp1 = (bull % 10 + '0');
            bull = bull / 10;
            b = temp1 + b;
        }
        
        string c = "";
        if(cow == 0)
            c = "0";
        while(cow) {
            char temp2 = (cow % 10 + '0');
            cow = cow / 10;
            c = temp2 + c;
        }
        
        string ans = b + 'A' + c + 'B';
        return ans;
    }
};
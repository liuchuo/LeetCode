151. Reverse Words in a String
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

分析：我用的方法是把字符串中的所有单词放入栈里，然后将栈里的所有字符串弹栈到字符串s中～

class Solution {
public:
    void reverseWords(string &s) {
        stack<string> sstack;
        int flag = 0;
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ' && flag == 0) {
                temp = "";
                temp += s[i];
                flag = 1;
            } else if(s[i] != ' ') {
                temp += s[i];
            } else if(s[i] == ' ' && flag == 1){
                sstack.push(temp);
                flag = 0;
            }
            if(i == s.length() - 1 && flag == 1)
                sstack.push(temp);
        }
        s = "";
        while(!sstack.empty()) {
            string temp = sstack.top();
            s += temp;
            sstack.pop();
            if(!sstack.empty())
                s += " ";
        }
    }
};
383. Ransom Note
 Given  an arbitrary  ransom  note  string and another string containing letters from  all the magazines,  write a function that will return true if the ransom  note can be constructed from the magazines ; otherwise, it will return false.  

Each letter  in  the  magazine string can  only be  used once  in  your ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

题目大意：给两个string，判断第一个string能否由第二个string里面所含有的字母组成，第二个string里面的所有字母只能使用一次~
分析：建立一个hash数组，对第二个string遍历并记录每个字符出现的次数，然后遍历第一个string，如果有出现hash里面不存在的字符，那么return false~~~~

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(256);
        for(int i = 0; i < magazine.size(); i++)
            hash[magazine[i]]++;
        for(int i = 0; i < ransomNote.size(); i++)
            if(hash[ransomNote[i]])
                hash[ransomNote[i]]--;
            else
                return false;
        return true;
    }
};
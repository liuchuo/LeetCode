127. Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the the same.

题目大意：给出beginWord、endWord和一个字典，找到从beginWord到endWord的最短转换序列，转换要求是：
1.每次只能改变一个字母～
2.变换过程中的中间单词必须在字典中出现～（第一个beginWord不需要出现，最后一个endWord需要在字典中出现～）
分析：用广度优先搜索～先将beginWord放入队列中，然后将队列中的每一个单词从头到尾换26个字母一遍～如果换后的单词在字典中能找到～而且没有被访问过～（如果每次都找访问过的就死循环啦，不停的变来变去变同一个咋办～）那就将这个单词放入队列中继续变换～直到有一次发现在字典中找到单词的时候，这个单词恰好是endWord为止～
因为要返回路径长度～所以在队列中放一个string和int组成的pair一对～这样的话用string表示单词，int表示变换到当前单词的路径～比如startWord就是1～之后每次加1～因为题目给的是vector～把他们所有单词先放到dict的set集合中查找单词会方便很多～visit标记当前单词是否被访问过～

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict, visit;
        for(int i = 0; i < wordList.size(); i++)
            dict.insert(wordList[i]);
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while(!q.empty()) {
            pair<string, int> temp = q.front();
            q.pop();
            string word = temp.first;
            for(int i = 0; i < word.length(); i++) {
                string newword = word;
                for(int j = 0; j < 26; j++) {
                    newword[i] = 'a' + j;
                    if(dict.find(newword) != dict.end() && visit.find(newword) == visit.end()) {
                        if(newword == endWord)
                            return temp.second + 1;
                        visit.insert(newword);
                        q.push(make_pair(newword, temp.second + 1));
                    }
                }
            }
        }
        return 0;
    }
};
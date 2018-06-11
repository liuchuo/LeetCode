657. Judge Route Circle
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false

题目大意：最初，位置（0，0）处有一个机器人。 给出它的一系列动作，判断这个机器人是否有一个圆圈，这意味着它回到原来的位置。移动顺序由一个字符串表示。 而每一个动作都是由一个人物来表现的。 有效的机器人移动R（右），L（左），U（上）和D（下）。 输出应该是真或假，表示机器人是否成圈。
分析：计算UDLR出现的次数保存在map中，如果U和D出现的次数相同且L和R出现的次数相同则为true～

class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> m;
        for(int i = 0; i < moves.length(); i++) m[moves[i]]++;
        return (m['L'] == m['R'] && m['U'] == m['D']);
    }
};
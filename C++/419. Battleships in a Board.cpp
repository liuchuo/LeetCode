419. Battleships in a Board
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

题目大意：给一张地图，战列舰用X表示，空地用.表示，战列舰只可能横着或者竖着一条，而且两条战列舰之间肯定有空地，计算战列舰的个数～
分析：其实只需要数战列舰的头部有几个就行了，因为战列舰要么横着要么竖着，它的头部肯定满足以下条件：1.它的上方是空地（或者边界） 2.它的左方是空地（或者边界）
这样遍历一遍地图上所有的点，如果当前点是X而且满足上面所述的两个条件，就将战列舰个数+1～～～

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;
        if(board.size() == 0) return 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'X' && (i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.'))
                    result++;
            }
        }
        return result;
    }
};
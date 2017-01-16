292. Nim Game 
Total Accepted: 59733 Total Submissions: 113879 Difficulty: Easy
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
/*
设甲乙一人一次为一轮。进行了很多轮之后，让甲选的时候，如果是1，2，3那就可以通过。如果是4一定不能赢，所以如果是5，6，7可以想办法分别取1，2，3让乙来一定不能赢，所以5，6，7甲是可以赢的。
如果是8，则无论甲选任何个数，都能让乙来面临7，6，5这些必赢的选项所以甲一定输。
如果是9，10，11，则甲可以通过让乙来面临8来一定输。
如果是12，则甲无论选取任何个数，都能让乙面临9，10，11这样的一定可以赢的数字，所以12让甲必定输。
以此类推发现规律，在4或者4的倍数的时候，甲无论怎样一定输。
所以就简单一句：return n % 4;
*/
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};
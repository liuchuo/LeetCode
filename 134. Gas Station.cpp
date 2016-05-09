134. Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station’s index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.
分析：
gas[i] – cost[i]为车行驶的代价。要想能走完一圈，必须时刻保持从出发点到终点始终行驶代价总和temp >= 0
0.假设从0开始出发，累积temp0一直是>=0的。到点A的时候发现<0了。此时可以想：从0~A的temp0小于0，而前面的0~某点的代价总和一直是>=0的，所以可以得知前面任何一点都不能作为出发点了，因为temp0 – 0~某点的代价总是小于0的不满足题意。所以只能从下一个结点开始尝试。
1.从A+1结点开始出发，累积temp1一直是>=0的。到点B的时候发现<0了。此时可以想：从A+1 ~ B的temp1小于0，那么前面的A+1到某点的代价总和一直是>=0的，所以可以得知前面任何一点都不能作为出发点了，因为temp1 – A+1~某点的代价总是小于0不和题意的。所以就从下一点开始尝试….
2.终于有一次可以从D开到n-1这个点了。只要看能不能车再从0开到D-1了。也就是想看temp2+temp0+temp1的过程中可不可能总代价小于0.结论是只要所有点总代价total>=0，那么一定可以开一圈。可以这么证明：total>=0 temp0 和temp1都是在最后一个点game over的 前面都是正数那么ok，最后一个数是导致<=0的点，但是去掉了temp0这个负数，总代价毫无疑问还是大于0的不用说。所以说最后只要total>=0那么就一定可以走结束一圈。啊哦- -我竟然说了这么多=_=


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty())
            return -1;
        int total = 0, temp = 0, index = 0;
        for(int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            if(temp >= 0) {
                temp += gas[i] - cost[i];
            } else {
                temp = gas[i] - cost[i];
                index = i;
            }
        }
        return total >= 0 ? index : -1;
    }
};
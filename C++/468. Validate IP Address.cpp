468. Validate IP Address
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.

题目大意：给一个字符串，判断它是不是IP地址，如果是IPv4地址，就返回IPv4；如果是IPv6地址，就返回IPv6；都不是的话返回Neither～
分析：首先根据地址中是否包含.或者:判断是IPv4还是IPv6的范畴～
如果是IPv4，则需要满足：
1.一共有3个"."
2.每个点之间的内容为数字，不能为空，且这个数字是0～255
3.没有前导的0，即不会出现001这样的数字（小技巧是字符串转化为数字再转化为字符串，看看和原来字符串是否一致）
如果是IPv6，则需要满足：
1.一共有7个":"
2.每个标点之间的内容为16进制数字，不能为空即只能包含数字、字母(a~f、A~F)

class Solution {
public:
    string validIPAddress(string IP) {
		for (int i = 0; i < IP.length(); i++) {
			if (IP[i] == '.')
				return isIPv4(IP) ? "IPv4" : "Neither";
			else if (IP[i] == ':')
				return isIPv6(IP) ? "IPv6" : "Neither";
		}
		return "Neither";
    }
private:
	bool isIPv4(string IP) {
		int dotcnt = 0;
		for (int i = 0; i < IP.length(); i++) {
			if (IP[i] == '.')
				dotcnt++;
		}
		if (dotcnt != 3) return false;
		string temp = "";
		for (int i = 0; i < IP.length(); i++) {
		    if (IP[i] != '.')
		        temp += IP[i];
		    if (IP[i] == '.' || i == IP.length() - 1) {
		        if (temp.length() == 0 || temp.length() > 3) return false;
		        for (int j = 0; j < temp.length(); j++) {
		            if (!isdigit(temp[j])) return false;
		        }
		        int tempInt = stoi(temp);
		        if (tempInt > 255 || tempInt < 0) return false;
		        string convertString = to_string(tempInt);
		        if (convertString != temp) return false;
		        temp = "";
		    }
		}
		if (IP[IP.length()-1] == '.') return false;
		return true;
	}

	bool isIPv6(string IP) {
		int dotcnt = 0;
		for (int i = 0; i < IP.length(); i++) {
			if(IP[i] == ':')
				dotcnt++;
		}
		if (dotcnt != 7) return false;
		string temp = "";
		for (int i = 0; i < IP.length(); i++) {
		    if (IP[i] != ':')
		        temp += IP[i];
		    if (IP[i] == ':' || i == IP.length() - 1) {
		        if (temp.length() == 0 || temp.length() > 4) return false;
		        for (int j = 0; j < temp.length(); j++) {
		            if (!(isdigit(temp[j]) || (temp[j] >= 'a' && temp[j] <= 'f') || (temp[j] >= 'A' && temp[j] <= 'F'))) return false;
		        }
		        temp = "";
		    }
		}
		if (IP[IP.length()-1] == ':') return false;
		return true;
	}
};
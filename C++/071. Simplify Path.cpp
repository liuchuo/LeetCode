71. Simplify Path
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

题目大意：简化一个Unix风格的绝对路径，返回简化后的结果～
分析：以"/"为分隔，将所有不是"."和".."的字符串放入栈中。如果是".."并且上一层不为空，就返回上一层，也就是弹栈；如果是"."，不处理；如果有多个连续的"/"，则只认一个"/"：
从头到尾遍历字符串，如果是"/"就不断跳过；当不是"/"的时候，将后面的字符串放入temp中，如果是".."就弹栈，如果不是".."和"."就把temp压入栈中。
最后将栈中所有的元素按照"/"分隔连接成result字符串～

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string result = "", temp = "";
        int i = 0, len = path.length();
        while (i < len) {
            while (i < len && path[i] == '/') i++;
            temp = "";
            while (i < len && path[i] != '/') temp += path[i++];
            if (temp == ".." && !s.empty())
                s.pop();
            else if (temp != "" && temp != "." && temp != "..")
                s.push(temp);
        }
        if (s.empty()) return "/";
        while (!s.empty()) {
            result = "/" + s.top() + result;
            s.pop();
        }
        return result;
    }
};
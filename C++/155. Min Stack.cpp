155. Min Stack   
My Submissions QuestionEditorial Solution
Total Accepted: 70109 Total Submissions: 318312 Difficulty: Easy
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Subscribe to see which companies asked this question


class MinStack {
public:
    stack<int> s;
    stack<int> min;
    
    void push(int x) {
        s.push(x);
        if(min.empty() || min.top() >= x) {
            min.push(x);
        }
    }//这里 if 语句里面是 >= 的原因是，假设有两个相同的最小值8，
    //如果只存一个（只填 > ），假设两个 stack 同时pop了一个8，
    //那么其实最小值还有8但是已经被 pop 掉了

    void pop() {
        if(s.top() == min.top()) {
            s.pop();
            min.pop();
        } else {
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
};
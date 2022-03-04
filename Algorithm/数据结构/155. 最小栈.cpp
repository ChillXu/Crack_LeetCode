\\
\\用单独一个栈，栈顶记录当前最小值
\\
class MinStack {
    stack<int> s,min_s;
public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(min_s.empty()||val<=min_s.top()){   \\ = 很关键，若有相同元素入栈，不插入min_s中，则后续min_s出栈会有问题
            min_s.push(val);
        }
    }
    
    void pop() {
        if(s.top()==min_s.top()){
            min_s.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

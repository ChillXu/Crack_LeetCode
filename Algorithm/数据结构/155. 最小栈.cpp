/*
 题目：设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

 实现 MinStack 类:
 MinStack() 初始化堆栈对象。
 void push(int val) 将元素val推入堆栈。
 void pop() 删除堆栈顶部的元素。
 int top() 获取堆栈顶部的元素。
 int getMin() 获取堆栈中的最小元素。
**/
//用单独一个栈，栈顶记录当前最小值
//
class MinStack {
    stack<int> s,min_s;
public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(min_s.empty()||val<=min_s.top()){   // = 很关键，若有相同元素入栈，不插入min_s中，则后续min_s出栈会有问题
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

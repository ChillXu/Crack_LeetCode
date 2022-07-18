class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> stk_min;
    MinStack() {

    }
    
    void push(int x) {
        if(stk.empty()){stk_min.push(x);}
        else if(x<=stk_min.top()){stk_min.push(x);}   //维护当前最小值栈
        stk.push(x);
    }
    
    void pop() {
        if(stk.top()==stk_min.top()){  //与当前栈内最小值相同则stk_min出栈
            stk_min.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> stk_min;
    MinStack() {

    }
    
    void push(int x) {
        if(stk.empty()){stk_min.push(x);}
        else{stk_min.push(::min(x,stk_min.top()));}  //每次将x和stk_min.top()中小的值入栈
        stk.push(x);
    }
    
    void pop() {
        stk_min.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

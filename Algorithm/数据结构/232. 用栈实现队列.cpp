//
//
//
class MyQueue {
    stack<int> in,out;
    void in2out(){
        while(!in.empty()){
            int x=in.top();
            in.pop();
            out.push(x);
        }
    }
public:
    MyQueue() {
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()){
            in2out();
        }
        int x=out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        if(out.empty()){
            in2out();
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//
//
//
class CQueue {
private:
    stack<int> stk_in,stk_out;
public:
    void in2out(){
        while(!stk_in.empty()){
            stk_out.push(stk_in.top());
            stk_in.pop();
        }
    }
    
    CQueue() {

    }
    
    void appendTail(int value) {
        stk_in.push(value);
    }
    
    int deleteHead() {
        if(stk_out.empty()){
            if(stk_in.empty()){
                return -1;
            }
            in2out();
        }
        int value=stk_out.top();
        stk_out.pop();
        return value;
    }
};

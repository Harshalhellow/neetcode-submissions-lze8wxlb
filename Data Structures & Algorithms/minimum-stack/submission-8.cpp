class MinStack {
public:
    stack<int>stk; 
    stack<int>minstk;
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if(minstk.empty()) minstk.push(val);
        else{
            if(val<minstk.top()) minstk.push(val);
            else minstk.push(minstk.top());
        }
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};

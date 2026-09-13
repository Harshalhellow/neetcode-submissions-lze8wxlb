class MinStack {
public:
        stack<int> stk;
        stack<int> minstack;
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if(!minstack.empty()){
            if(minstack.top()>=val) minstack.push(val);
        }
        else minstack.push(val);
    }
    
    void pop() {
        
        if(!stk.empty()&&!minstack.empty()&&stk.top()==minstack.top())minstack.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

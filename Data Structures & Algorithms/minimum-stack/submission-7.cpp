class MinStack {
public:
    stack<int> real;
    stack<int> minstack;
    MinStack() {

    }
    
    void push(int val) {    
        if(real.empty()){
            MinStack::minstack.push(val);
            MinStack::real.push(val);
        }
        else{
        MinStack::real.push(val);
        MinStack::minstack.push(min(MinStack::minstack.top(),val));
        }


     }
    
    void pop() {
        MinStack::real.pop();
        MinStack::minstack.pop();
    }
    
    int top() {
        return MinStack::real.top();
    }
    
    int getMin() {
        return MinStack::minstack.top();
    }
};

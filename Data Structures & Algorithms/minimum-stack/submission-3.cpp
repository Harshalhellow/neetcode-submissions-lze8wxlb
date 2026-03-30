class MinStack {
public:
    stack<int> stk;
    stack<int> min;
    int currentmin = INT_MAX;
    MinStack() {
       
    }
    
    void push(int val) {
        stk.push(val);
        if(currentmin>val){
            currentmin = val;
        }
        min.push(currentmin);
    }
    
    void pop() {
        stk.pop();
        min.pop();
        if(min.empty()) currentmin = INT_MAX;
        else currentmin = min.top();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min.top();
    }
};
// just a vector 
// initalise a vector 
// push inserts the element at position 0;
// pop removes teh element from the last index 
//top just looks at the last element 
// we just keep track of the most min element every time min gets added 

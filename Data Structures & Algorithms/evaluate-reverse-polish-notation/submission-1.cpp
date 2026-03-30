class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int a, b;
        for(auto& token:tokens){
            if(token == "+"){
                a = stack.top(); 
                stack.pop();
                b = stack.top();
                stack.pop();
                b +=a;
                stack.push(b); 
            }
            else if(token == "-"){
                a = stack.top(); 
                stack.pop();
                b = stack.top();
                stack.pop();
                b -=a;
                stack.push(b); 
            }
            else if(token == "*"){
                a = stack.top(); 
                stack.pop();
                b = stack.top();
                stack.pop();
                b *=a;
                stack.push(b); 
            }
            else if(token == "/"){
                a = stack.top(); 
                stack.pop();
                b = stack.top();
                stack.pop();
                b /=a;
                stack.push(b); 
            }
            else {
                stack.push(stoi(token));
            }
        }
        return stack.top();


    }
};


// go through all elements in the list
// create a stack 
// if its a number it goes on the stack 
// set up a and b 
// b is the ongoing number 
// a is the new number 
// put b back on the stack 

// if the element is a plus and minus multiply and divide
// do the corresponding plus minus thing  
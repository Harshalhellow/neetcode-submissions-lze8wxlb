class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for(auto& c:s){
            if(c=='('||c=='{'||c=='['){
                stack.push(c);
            }
            else {
                if(stack.size()==0) return false;
                char temp = stack.top();
                stack.pop();
                if(c==')' && temp != '(') return false;
                if(c=='}' && temp != '{') return false;
                if(c==']' && temp != '[') return false;
            }
        }
        if(stack.size()==0) return true;
        else return false;
        
    }
};

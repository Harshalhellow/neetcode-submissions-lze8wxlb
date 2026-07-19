class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // opening braces
        // for loop that will add opening braces to stk1 and check if closing brace are on top
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{') stk.push(s[i]);
            else if(s[i]==')'&&!stk.empty()&&stk.top()=='('||s[i]==']'&&!stk.empty()&&stk.top()=='['||s[i]=='}'&&!stk.empty()&&stk.top()=='{') stk.pop();
            else return false; 
        }
        if(stk.empty())return true; 
        else return false; 
    }
};
/* 
()(
stack 1 
 */

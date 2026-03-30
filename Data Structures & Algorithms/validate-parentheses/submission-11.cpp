class Solution {
public:
    bool isValid(string s) {
        stack<char>openingbracket; 
        char temp;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                openingbracket.push(s[i]);
            }
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(openingbracket.empty()) return false; 
                temp = s[i];
                if(temp==')'&& openingbracket.top()!='(')return false;
                if(temp=='}'&& openingbracket.top()!='{')return false;
                if(temp==']'&& openingbracket.top()!='[')return false;
                openingbracket.pop();
            }
        }
        if(!openingbracket.empty()) return false;
        return true; 
    }
};


// we store opening brackets 
// when we finding a closing bracket we pop the top thing of the stack 
// if its the matching set we know its good 
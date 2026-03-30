class Solution {
public:
    bool isValid(string s) {
        stack<char> opening; 
        char top;
        if(s.size()%2!=0)return false;
        for(auto c:s){
            if(c=='('||c=='{'||c=='[')opening.push(c);
            else{
                if(opening.empty()) return false;
                top = opening.top();
                if(c==')' && top!='(') return false;
                if(c=='}' && top!='{') return false;
                if(c==']' && top!='[') return false;
                opening.pop();
            }

        }
        if(opening.empty()==false)return false;
        return true;
    }
};

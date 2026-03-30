class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If it's an opening bracket, push to stack
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } 
            // If it's a closing bracket
            else {
                if (stk.empty()) return false; // no match

                char top = stk.top();
                stk.pop();

                // Check if brackets match
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        // At the end, the stack should be empty if valid
        return stk.empty();
    }
};

// store opening brackets 
//if closing brackets found pop the top of the stack if it doesnt match return false
// 

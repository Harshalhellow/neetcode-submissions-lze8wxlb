class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int a;
        int b;
        int res;
        int pushback;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"){
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                res = a + b;
                numbers.push(res);
            }
            else if(tokens[i]=="-"){
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                res = b - a;
                numbers.push(res);
            }
            else if(tokens[i]=="*"){
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                res = a * b;
                numbers.push(res);
            }
            else if(tokens[i]=="/"){
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                res = b/a;
                numbers.push(res);

            }
            else{
                pushback = stoi(tokens[i]);
                numbers.push(pushback);
            }
        }
        return numbers.top();
    }
};

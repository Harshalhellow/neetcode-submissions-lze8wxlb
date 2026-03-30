class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>numbers; 
        int a;
        int b;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="*"){
                a = numbers.top();
                numbers.pop();
                b= numbers.top();
                numbers.pop();
                numbers.push(a*b);
            }
            if(tokens[i]=="+"){
                a = numbers.top();
                numbers.pop();
                b= numbers.top();
                numbers.pop();
                numbers.push(b+a);
            }
            if(tokens[i]=="-"){
                a = numbers.top();
                numbers.pop();
                b= numbers.top();
                numbers.pop();
                numbers.push(b-a);
            }
            if(tokens[i]=="/"){
                a = numbers.top();
                numbers.pop();
                b= numbers.top();
                numbers.pop();
                numbers.push(b/a);
            }
            if(tokens[i]!="*" && tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="/"){
                numbers.push(stoi(tokens[i]));
            }
        }
        return numbers.top();
        
    }
};


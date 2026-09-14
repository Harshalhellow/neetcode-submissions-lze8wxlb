class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> integers; 
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="*"){
                int a = integers.top();
                integers.pop();
                int b = integers.top();
                integers.pop();
                integers.push(a*b);
            }
            else if(tokens[i]=="+"){
                int a = integers.top();
                integers.pop();
                int b = integers.top();
                integers.pop();
                integers.push(a+b);
            }
            else if(tokens[i]=="/"){
                int a = integers.top();
                integers.pop();
                int b = integers.top();
                integers.pop();
                integers.push(b/a);
            }
            else if(tokens[i]=="-"){
                int a = integers.top();
                integers.pop();
                int b = integers.top();
                integers.pop();
                integers.push(b-a);
            }
            else integers.push(stoi(tokens[i]));
        }
        return integers.top();
    }
};

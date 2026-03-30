class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers; // Stack to store operands

        for (const string& token : tokens) { // Iterate through tokens in order
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the last two numbers
                int b = numbers.top(); numbers.pop();
                int a = numbers.top(); numbers.pop();
                
                // Perform the operation
                if (token == "+") a += b;
                else if (token == "-") a -= b;
                else if (token == "*") a *= b;
                else if (token == "/") a /= b;

                // Push the result back onto the stack
                numbers.push(a);
            } else {
                // Convert string to integer and push onto stack
                numbers.push(stoi(token));
            }
        }
        return numbers.top(); // Final result is at the top of the stack
    }
};



// put all elements in stack in reverse order
// pop the elements off the stack 
// // create a temp number for the first thing
// keep using that number 
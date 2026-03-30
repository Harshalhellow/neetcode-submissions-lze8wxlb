class Solution {
public:
    vector<string> generateParenthesis(int n) {
           vector<string> res; // Result vector
        string current; // Current string being built
        backtrack(res, current, 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string>& res, string current, int openCount, int closeCount, int n) {
        // Base case: When the current string length is 2*n, add it to results
        if (openCount == n && closeCount == n) {
            res.push_back(current);
            return;
        }

        // If we can add an opening parenthesis, do so
        if (openCount < n) {
            backtrack(res, current + '(', openCount + 1, closeCount, n);
        }

        // If we can add a closing parenthesis, do so
        if (closeCount < openCount) {
            backtrack(res, current + ')', openCount, closeCount + 1, n);
        }
    }
};


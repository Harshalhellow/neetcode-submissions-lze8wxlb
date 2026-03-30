class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        
        // Filter out non-alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {  // Check if character is a letter or digit
                res.push_back(tolower(c));  // Convert to lowercase and add to res
            }
        }
        
        // Two-pointer approach to check for palindrome
        int left = 0, right = res.size() - 1;
        
        while (left < right) {
            if (res[left] != res[right]) {
                return false;  // Mismatch found, not a palindrome
            }
            left++;
            right--;
        }
        
        return true;  // No mismatches found, it's a palindrome
    }
};


// two pointers
// one starts at the end one starts at the beggining
// if both are the same return true 
// if both are next to each other i.e indexes are one apart then stop and return true 

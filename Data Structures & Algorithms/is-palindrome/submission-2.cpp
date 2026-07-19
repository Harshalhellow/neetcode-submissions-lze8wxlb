class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1; 

        // while loop that stops if left becomes equal to or greater than right
        while(left<right){
            // check if it an alpha charater and if uppercase conver to lower and compare
            while(!isalnum(s[left])&&left<right) left++;
            while(!isalnum(s[right])&&left<right) right--;
            if(left>=right) break; 
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;
        }        
        return true; 
    }
};


// You would have two pointers start at either end
// check if it is an alphabatic character, if it uppercase conver to lower and compare if true continue
// if false return false

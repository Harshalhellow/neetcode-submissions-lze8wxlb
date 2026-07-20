class Solution {
public:
    bool isPalindrome(string s) {
        //create two pointers
        int left = 0;
        int right = s.size()-1;

        while(left<right){
            while(!isalnum(s[left])&&left<right) left++;
            while(!isalnum(s[right])&&left<right) right--;
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;

        }
        return true; 
        // while pointers are not equal 

        // if they are alpah or number conver tot lower and check 
        // if not alphaor number increment and decrement 
    }
};


/*
we take a two pointer apprach 
we check if both sides are alpha or a number if they are then we compare and see if it teh same if they are captial conver to lower then compare
if not alpha or number increment or decrement to the geto teh right value
*/
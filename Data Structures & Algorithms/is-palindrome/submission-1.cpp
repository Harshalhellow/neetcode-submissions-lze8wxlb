class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;;
        int right = s.size();
        for(int i=0; i<s.size(); i++){
            if(isalnum(s[left])==false){
                left++;
                continue;
            }
            if(isalnum(s[right])==false){
                right--;
                continue;
            }
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;
            if(left==right) break;
        }
        return true;
        
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int left =0;
        int right = s.size()-1;
        while(left<=right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            else if(!isalnum(s[right])){
                right--;
                continue; 
            }
            if(isdigit(s[left])||isdigit(s[right])){
                if(!(isdigit(s[left])&&isdigit(s[right]))) return false;
                if(s[left]!=s[right]) return false;
            }
            if(isalpha(s[left])||isalpha(s[right])){
                if(!(isalpha(s[left])&&isalpha(s[right]))) return false;
                if(tolower(s[left])!=tolower(s[right])) return false;
            }
            left++;
            right--;
        }        
        return true; 
    }
};


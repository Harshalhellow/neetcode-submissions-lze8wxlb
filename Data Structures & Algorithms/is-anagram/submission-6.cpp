class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> schar;
        unordered_map<char,int> tchar;
        if(s.size()!=t.size()) return false; 
        for(int i=0; i<s.size(); i++){
            schar[s[i]] +=1;
            tchar[t[i]] +=1; 
        }

        for(int i=0; i<s.size(); i++){
            if(schar[s[i]] != tchar[s[i]]) return false; 
        }
        return true; 
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length() || s.length()==0)return false;
        int temp;
        int i =0;
       while(s.length()>0){
            if(t.npos == t.find(s[i])) return false; 
            temp = t.find(s[i]);
            s.erase(i,1);
            t.erase(temp,1);
        }

        return true;

    }
};

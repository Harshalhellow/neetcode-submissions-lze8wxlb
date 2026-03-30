class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> smap,tmap;
        if(s.size()!=t.size()) return false;
        for(int i=0; i<s.size(); i++){
            smap[s[i]] +=1;
            tmap[t[i]] +=1;
        }
        for(auto& s:smap){
            if(smap[s.first] != tmap[s.first]) return false;
        }
        return true;
    }
};

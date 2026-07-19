class Solution {
public:
    bool isAnagram(string s, string t) {
        // check if they are the same size 
        if(s.size()!=t.size()) return false;
        // create hasmaps
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        // for loop to addd everything to both hasmaps
        for(int i=0; i<s.size(); i++){
            smap[s[i]] +=1;
            tmap[t[i]] +=1;
        }
        // another for loop to check if both are the same size
        for(int i=0; i<s.size(); i++){
            if( smap[s[i]]!= tmap[s[i]]) return false;
        }
        return true; 
    }
    /*
    we could you use a hasmap and store the int counts of it and then look for each character if they are the same
    this would be of o n+m of time and o 1 of space because theree is only a litmited abmount eof characters
    */
};

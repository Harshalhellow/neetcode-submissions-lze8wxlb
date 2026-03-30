class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int>  count(26,0);
        for(int i=0; i<s.size(); i++){
            count[t[i]-'a']--;
            count[s[i] -'a']++;

        }

        for(int i=0; i<count.size(); i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
};


// could create a hashmap of all seen strings and thier frequencies 
// could  create a second hashmap of the same thing 
// compare both hashmaps 
// o(n) time n bieng the combined lenght of both s and t 
// and o(n) of space 


// sort both strings 
// create a for loop to loop over both strings and see if they are both the same 
// o(n log n) however this would only take o(1) of space 


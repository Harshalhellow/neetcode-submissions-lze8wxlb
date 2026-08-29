class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> results;
       map<vector<int>,vector<string>> lexigrpahicalrep;
       for(int i=0; i<strs.size(); i++){
        vector<int>word(26,0);
        for(int j=0; j<strs[i].size(); j++){
            word[strs[i][j]-'a']++;
        }
        lexigrpahicalrep[word].push_back(strs[i]);
       }

       for(auto& value:lexigrpahicalrep){
        results.push_back(value.second);
       }
       return results;
    }
};
// we could create a hashtable with the key represting the lexigraphical count of each word
// The value pair being the vector that contains the other words that match it
// At the end go through our whole hashtable and then add them to our results list

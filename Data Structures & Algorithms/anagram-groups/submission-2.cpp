class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string,vector<string>> lexigrpohicalpair;
        string lexigrophical(26,'0');
        vector<string>temp;
        for(int i=0; i<strs.size(); i++){
            for(int j=0; j<strs[i].size();j++){
                lexigrophical[strs[i][j]-97] = ((lexigrophical[strs[i][j]-97]-'0')+1)+'0';
            }
            if(lexigrpohicalpair.find(lexigrophical)!=lexigrpohicalpair.end()){
                lexigrpohicalpair.find(lexigrophical)->second.push_back(strs[i]);
                    for(int k=0; k<26; k++){
                        lexigrophical[k] = '0';
                    }
            } 
            else {
            lexigrpohicalpair[lexigrophical].push_back(strs[i]);
                for(int k=0; k<26; k++){
                    lexigrophical[k] = '0';
                }
            }

        }
        for(auto i:lexigrpohicalpair){
            answer.push_back(i.second);
        }
        return answer;
    }
};


// create an hashmap of all strings 
// hashamap  has key value pairs of each strings lexigraphical value and thier index
// find a thing with a similar index if none exsist create a group in answer if one exsist add yourself to that group 


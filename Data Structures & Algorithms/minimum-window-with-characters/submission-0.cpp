class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>characterarrayS;
        unordered_map<char,int>characterarrayT; 
        for(auto a:t){
            characterarrayT[a]++;
        }
        int have = 0;
        int need = characterarrayT.size();
        int length = 0;
        int bestlenght = INT_MAX;
        pair<int,int> result = {0,0};
        int left =0;
        for(int i=0; i<s.size(); i++){
            characterarrayS[s[i]]++;
            length++;
            if(characterarrayS[s[i]]== characterarrayT[s[i]]) have++;
            while(have==need){
                if(bestlenght > length){
                    bestlenght = length;
                    result = {left,i};
                };
                characterarrayS[s[left]]--;
                if(characterarrayS[s[left]] <characterarrayT[s[left]]) have--;
                left++;
                length--;
            }
        }

        return bestlenght == INT_MAX ? "":s.substr(result.first,bestlenght);
    }
};


// create a left and right 
// find a valid solution by increasing r 
// if better than old solution update
// if not increment l to see if it is still a valid solution 
//
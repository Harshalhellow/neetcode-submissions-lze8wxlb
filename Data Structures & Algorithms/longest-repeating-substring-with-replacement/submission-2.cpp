class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxfrequency = 0;
        int counter = 0;
        int highestcounter = 0;
        unordered_map<char,int>charactercount;
        for(int i=0; i<s.size(); i++){
            charactercount[s[i]]++;
            maxfrequency  = max(maxfrequency,charactercount[s[i]]);
            while((i-l+1-maxfrequency)>k){
                charactercount[s[l]]--;
                maxfrequency  = max(maxfrequency,charactercount[s[i]]);
                l++;
                counter--;
            } 
            counter++;
            if(counter>highestcounter) highestcounter = counter;
            
        }
        return highestcounter;

        
    }
};

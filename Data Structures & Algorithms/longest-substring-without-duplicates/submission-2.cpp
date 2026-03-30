class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = left;
        int currentcounter = 0;
        int highestcount = 0;
        unordered_map<char,int>hashmap;
        while(right<=s.size()){
            hashmap[s[right]] +=1; 
            if(currentcounter>highestcount) highestcount = currentcounter;
            if(hashmap[s[right]]>1) {
                while(hashmap[s[right]]>1){
                    hashmap[s[left]] -=1;
                    left++;
                    currentcounter--;
                }
                currentcounter++;
            }
            else   currentcounter++;
            right++;
            
            
        }
        return highestcount;
    }
};


// left 
// right 
//hashmap 
// keep adding things to hashmp 
// if we find something that repeats reset hashmap update left to right 
// counter keep track of the largest substring and currnet
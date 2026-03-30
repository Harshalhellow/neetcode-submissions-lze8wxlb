class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // create a set that holds all the numbers o(n) if unordered
        unordered_set<int> SET(nums.begin(),nums.end());
        // see if each number is the begining of a streak by seeing if there is a number to the left of it 
        int streak =0;
        int maxstreak =0;
        for(auto& n:nums){
            if(SET.find(n-1) == SET.end()){
                streak++;
                while(SET.find(n+streak)!=SET.end()){
                    streak++;
                }
            maxstreak = max(maxstreak,streak);
            streak =0;
            }
        }
        return maxstreak;
    }
};




// if there is a number to the left it is if not then no 
// if a streak beggining is found see how long streak goes for
// have a  maxstreak and a current streak to keep track of the biggest streak
// return maxstreak 
// time(2n) reduces to o(n)
// space o(n) 

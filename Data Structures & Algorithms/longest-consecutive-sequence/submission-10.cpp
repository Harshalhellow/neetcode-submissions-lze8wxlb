class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]]++;
        }
        int current =0;
        int longest =0;
        for(auto& s:hashmap){
            if(!hashmap.contains(s.first-1)){
                int i=0;
                while(hashmap.contains(s.first+i)){
                current++;
                i++;
            }
            if(longest<current) longest = current; 
            current = 0; 
            }

        }

        return longest; 
        
    }
};

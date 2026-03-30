class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> hash;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]] +=1; 
            if(hash[nums[i]]>1) return true;
        }
        return false;
    }
};

// set up a dictionary 
// assign numbers in a dictionary 
// if the number goes up more than once return false 
// if all go through return true
//o(n) space
//o(n) time
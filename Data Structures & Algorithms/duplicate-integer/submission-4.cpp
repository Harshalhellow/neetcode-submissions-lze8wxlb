class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false; 
        unordered_map<int,int> hash;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]] +=1;
            if(hash[nums[i]]>1) return true;  
        }
        return false; 
    }
};
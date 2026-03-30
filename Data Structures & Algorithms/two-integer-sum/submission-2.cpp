class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int newtarget;
        for(int i=0; i<nums.size(); i++){
            newtarget = target-nums[i];
            if(hash.find(newtarget)!= hash.end()) return {hash.find(newtarget)->second,i};  
            hash[nums[i]] = i;  
        }
        return{9,9};

    }
};








// we could build a hashmap  and add all elements to it and what we need next to it 
// we could go throgh the whole hashmap again and then see if that target number is the hash map 


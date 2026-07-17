class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> answers; 
        for(int i=0; i< nums.size(); i++){
            if(!hash.count(target-nums[i])){
                hash[nums[i]] = i; 
            }
            else{
                answers.push_back(min(hash[target-nums[i]],i));
                answers.push_back(max(hash[target-nums[i]],i));
                return answers;
            }
        }
        return answers; 
    }
};

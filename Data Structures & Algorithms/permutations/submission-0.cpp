class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>curr; 
        int index =0;
        int size = nums.size();
        if(size==0) answer.push_back(curr);
        permutehelper(nums,answer,curr,index,size);
        return answer;
    }
    void permutehelper(vector<int>& nums, vector<vector<int>>&answer, vector<int>curr, int index, int size){
        if(curr.size()==size) {
            answer.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            curr.push_back(nums[i]);
            int temp = nums[i];
            nums.erase(nums.begin()+i);
            permutehelper(nums,answer,curr,i,size);
            nums.insert(nums.begin()+i,temp);
            curr.pop_back();
        }

    }
};

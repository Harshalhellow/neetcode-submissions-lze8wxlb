class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>solution; 
        vector<int> t;
        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i]+nums[j]+nums[k]==0) {
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        sort(t.begin(),t.end());
                        solution.push_back(t);
                        t.clear();
                    }
                }
            }

        }
        if(solution.size()>1){
        sort(solution.begin(),solution.end());
        auto last = unique(solution.begin(),solution.end());
        while(last != solution.end()){
                solution.erase(last,solution.end());
                last = unique(solution.begin(),solution.end());
            }
        }


        return solution; 
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> frequency(nums.size()+1);
        unordered_map<int,int> counts; 
        vector<int> res;
        for(int i =0; i<nums.size(); i++){
            counts[nums[i]]++;
        }

        for(auto& count:counts){
            frequency[count.second].push_back(count.first);
        }

        for(int i=frequency.size()-1; i<0; i--){
            if(res.size()==k) return res; 
            if(frequency[i].size()>0) res.insert(res.end(),frequency[i].begin(),frequency[i].end());
        }
    }
};



/*
we create a frequency buckets for each possible number from 1 to n 
then we go through and using a hashmap find the frequencies of each counts
we then place the keys of the hashmaps in thier values in the original frequency buckets 
then we go throgh and start from n all the way to 1 and push it in k times 



*/

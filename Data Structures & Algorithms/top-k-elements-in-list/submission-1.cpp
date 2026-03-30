class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        for(auto& n:nums){
            frequency[n]++; 
        }

        vector<pair<int, int>> allk;
        for(auto n:frequency){
            allk.push_back({n.second,n.first});
        }

        sort(allk.rbegin(), allk.rend());
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(allk[i].second);
        }
        return res;
    }
};

// create a hashmpa of the numbers to thier frequencies 
// create a vector to hold all the frequencies 
// sort that vector in reverse order 
// return those numbers corresponding values 



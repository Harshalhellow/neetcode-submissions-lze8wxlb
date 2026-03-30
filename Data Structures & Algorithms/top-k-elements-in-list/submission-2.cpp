class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>kfrequency;
        vector<int> answer;
        for(int i=0; i<nums.size(); i++){
            kfrequency[nums[i]] +=1; 
        }
        pair<int,int> highest;
        for(int i=0; i<k; i++){
            highest = {0,0};
            for(auto d:kfrequency){
                if(highest.second<d.second) highest = d;
            }
            kfrequency.erase(highest.first);
            answer.push_back(highest.first);
        }
        return answer;
    }
};


//ordered map storing elemenets and frequency 
// store elements in map 
// go through each element and pop the things out


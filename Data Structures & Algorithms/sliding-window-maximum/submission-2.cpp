class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = left;
        map<int,int> mapofmaps;
        int total = 0;
        vector<int> results;
        while(right<nums.size()){
            while(total<k){
                mapofmaps[nums[right]]++;
                total++;
                right++;
            }
            results.push_back(mapofmaps.rbegin()->first);
            mapofmaps[nums[left]]--;
            if(mapofmaps[nums[left]]==0) mapofmaps.erase(nums[left]);
            left++;
            total--;
        }

        return results;
    }
};


// create a sorted map
// add elements to the left and remove the elments from the right
// return the max element 


// we have a map of keys to thier frequencies 
// when removing an elment we only erase if it is at value 0; 

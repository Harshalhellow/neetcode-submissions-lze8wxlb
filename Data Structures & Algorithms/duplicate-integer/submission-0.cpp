class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // to create  a hash map of all elements and thier frequencey 
        unordered_map<int, int> map; 
        for(auto& n: nums){
            map[n]++;
        }

        // go thorugh hashmap and see if any values is equal to 2 
        for(auto &n: nums){
            if(map[n] != 1)return true;
        }

        return false;


    }
};




// o(n) time 
// o(n) space 

// sort the array 
// go through the array with two variables 
// if the variables are ever the same return false 
// o(n log n) time 
// o(1)
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //hashmap 
        unordered_map<int,int> hash;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]] +=1;
            if(hash[nums[i]]>1) return true;  
        }
        return false; 
        // for() go through the whole thing
            // add to hashmap and increment by 1 
            // if hashmap value greater than one return true else continue
    }
};


/* 
[1,2,3,4,4] return true has duplicate
[1,2,3,4] return false no duplicate 
can there be negative numbers 
and how big of numbers 
a simple solution would be to have a hashmap 
you add things to the hashmap as you see them 
after adding you incremnt by one 
then you look up that index again and if it is above one you return true
if you go through the whole array without finding any such as case you would return false
o(n) time o(n) space


*/
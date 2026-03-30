class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productofall = 1;
        int beforezeoro =1;
        int zerocount = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
            productofall *= nums[i];
            beforezeoro *= nums[i];
            } 
            else{
                 productofall *= nums[i];
                 zerocount++;
            }

        }
        vector<int> answer;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0 && zerocount ==1){
                answer.push_back(beforezeoro);
            }
            if(nums[i] == 0 && zerocount >1){
                 answer.push_back(0);
            }
            if(nums[i] != 0){
                answer.push_back(productofall/nums[i]);
            }
        }

        return answer;

    }
};
// get product of all numbers o(n)
// go through and add all elmeents and divide product of all numbers by that integer
// insert into arrya 
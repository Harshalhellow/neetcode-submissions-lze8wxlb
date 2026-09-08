class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numberofs = 0;
        int product = 1; 
        vector<int> answer;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0) product *= nums[i];
            if(nums[i]==0) numberofs++;
        }

        for(int i=0; i<nums.size(); i++){
            if(numberofs>1) answer.push_back(0);
            if(numberofs==1&&nums[i]==0) answer.push_back(product);
            if(numberofs==1&&nums[i]!=0) answer.push_back(0);
            if(numberofs==0) answer.push_back(product/nums[i]);
        }
        
        return answer; 
    }
};


/* 
The most basic solution would be to times eveything together 
store that value then go through each intger and divide it 

This would break in the case of 0s because once we get to the index where the value is 0 we dont know what that would have been 

we can solve this by just ignoring 0s when timsing it and when we find a 0 we see how many 0s we found if we found more than 1 then the answer is 0 if we found only 1 than the answer is that non 0 multiple 

*/
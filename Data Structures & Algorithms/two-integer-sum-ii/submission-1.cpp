class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size()-1;
        while(numbers[index1]+numbers[index2]!= target){
            if(numbers[index1]+numbers[index2]>target){
                index2--;
            }
             if(numbers[index1]+numbers[index2]<target){
                index1++;
            }

        }
        vector<int> res;
        res.push_back(index1+1);
        res.push_back(index2+1);
        return res; 
    }
};


// intialise two pointers on the either side 
// if the left plus right > target then decrement the right
// if the left plus right < target then increment the left 
// return the indexes when these two for loops exit andd 1 to index because the answer is 1-indexed 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer; 
        int start=0;
        int end = numbers.size()-1;
        while(numbers[start]+numbers[end] != target){
            if(numbers[start]+numbers[end]>target)end--;
            if(numbers[start]+numbers[end]<target)start++;
        }
        answer.push_back(start+1);
        answer.push_back(end+1);
        return answer; 
    }
};

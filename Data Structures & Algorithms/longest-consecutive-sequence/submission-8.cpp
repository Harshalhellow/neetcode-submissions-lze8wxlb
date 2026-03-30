class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool>sequence;
        int counter =1;
        int longestsequence =0;
        if(nums.size()==1) return 1;
        if(nums.size()==0) return 0;
        for(auto i:nums){
            sequence[i] = true;
        }
        if(sequence.size()==1) return 1;
        for(auto i:sequence){
            if(sequence.find(i.first+1)!=sequence.end()){
                counter++;
                if(longestsequence < counter) longestsequence = counter;
            }
            else counter = 1;
        }

        return longestsequence;
    }
};

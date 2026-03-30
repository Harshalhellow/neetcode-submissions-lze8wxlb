class Solution {
public:
    int findMin(vector<int> &nums) {

        if(nums.size()==1) return nums[0];
        int left = 0;
        int right = nums.size()-1;
        int leftcounter = 0;
        int rightcounter = 0; 
        while(nums[right]<nums[left]){
            if(nums[right]<nums[left]){
                rightcounter++;
                right -= 1; 
            }
            else{
                leftcounter++;
                left +=1;
            }
        }
        std::cout << "counter value left" << leftcounter << std::endl;
        std::cout << "counter value right" << rightcounter << std::endl;
        int counter;

        if(rightcounter>leftcounter) counter = rightcounter;
        else counter = leftcounter;
        for(int i=0; i<counter; i++){
            std::cout << "element at the start of the array is " << nums[0] << std::endl;
            nums.insert(nums.begin(),nums[nums.size()-1]);
            std::cout << "element at the start of the array is after insertion" << nums[0] << std::endl;
            nums.erase(nums.end());
            std::cout << "element at the end of the array is " << nums[nums.size()-1] << std::endl;
        }
        
        return nums[0];
    }
};

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int kis;
    KthLargest(int k, vector<int>& nums) {
        kis = k; 
        for(int i=0; i<nums.size(); i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>kis) minHeap.pop();
        }
        
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>kis) minHeap.pop();
        return minHeap.top();
        
    }
};

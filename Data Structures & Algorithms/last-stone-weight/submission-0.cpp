class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>> maxheap; 
        for(int i=0; i<stones.size(); i++){
            maxheap.push(stones[i]);
        }

        while(maxheap.size()>1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            if(x<y){
                y -=x;
                maxheap.push(y); 
            }
            else if(y<x){
                x -=y;
                maxheap.push(x);
            }
        }
        if(maxheap.size()==0) return 0;
        else return maxheap.top();
        
    }
};


// we create a max heap add all elments to it 
// we pop the two elements from the max heap 
// we apply the if else case
// we put the new remaining thing in the max heap i fneeded 
// we keep going until heap size is 0 and or 1
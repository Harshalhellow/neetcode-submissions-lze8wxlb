class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        if(abs((maxheap.size()-minheap.size())>1)){
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        } 
        if(maxheap.size()>0&&minheap.size()>0&&maxheap.top()>minheap.top()){
            int temp1 = maxheap.top();
            int temp2 =  minheap.top();
            maxheap.pop();
            minheap.pop();
            maxheap.push(temp2);
            minheap.push(temp1);
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()) return double (maxheap.top()+minheap.top())/2;
        else return maxheap.top();
    }
};


// max  heap 3 1
// min heap  2 
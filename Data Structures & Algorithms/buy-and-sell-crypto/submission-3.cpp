class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1) return -1;
        int left = 0;
        int right = 1;
        int currprofit = 0;
        int maxprofit = 0; 
        while(right<prices.size()){
            if(prices[left]>prices[right]) left = right;
            else currprofit = prices[right]-prices[left]; 
            if(maxprofit<currprofit) maxprofit = currprofit;
            right ++; 
        }
        return maxprofit;
    }
};

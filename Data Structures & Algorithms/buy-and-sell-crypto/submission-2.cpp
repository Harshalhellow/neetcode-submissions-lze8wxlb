class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = l+1;
        int currentprofit =0;
        int maxproffit = 0;
        while(r<prices.size()){
            if(prices[l]>prices[r]) l =r;
            else currentprofit = prices[r]-prices[l];
            if(currentprofit>maxproffit) maxproffit = currentprofit;
            r++;
        }

        return maxproffit;
        
    }
};

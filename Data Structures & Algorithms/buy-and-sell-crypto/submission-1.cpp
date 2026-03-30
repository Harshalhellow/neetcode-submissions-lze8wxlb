class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l =0;
        int r = prices.size()-1;
        int currentprofit = 0;
        int maxprofit = 0;
        for(int i=0; i<prices.size(); i++){
            l = i+1;
            while(l<=r){
                currentprofit = prices[l]-prices[i];
                if(currentprofit>maxprofit) maxprofit = currentprofit;
                l++;
            }
        }

        return maxprofit; 

    }
};

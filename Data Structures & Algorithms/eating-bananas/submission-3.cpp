class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max  =0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]>max) max = piles[i]; 
        }
        int highestk = 0;
         if(max%(h/piles.size())==0) highestk = max/(h/piles.size());
         else highestk = max/(h/piles.size()) +1;
         max/(h/piles.size());
        int left = 1;
        int m;
        int currentk = highestk;
        int currentkcount = 0;
        while(left<=highestk){
            m = (left+highestk)/2;
            std::cout << "middle is " << m << std::endl;
            for(int i=0; i<piles.size(); i++){
                 std::cout << "entered the for loop" << std::endl;
                if(piles[i]%m==0){
                    currentkcount += piles[i]/m;
                    std::cout << "triggered1" << std::endl;
                } 
                else {
                    currentkcount += piles[i]/m + 1;
                    std::cout << "triggered2" << std::endl;}

                    }
            if(currentkcount > h){
                std::cout << "current count is before left got changed " << currentkcount << std::endl;
                left = m + 1;
                currentkcount = 0;
                std::cout << "current count is when left got changed " << currentkcount << std::endl;
                std::cout << "current value of left  " << left << std::endl;
                std::cout << "current value of right " << highestk << std::endl;
            } 
            else if(currentkcount <= h){
                currentkcount = 0;
                std::cout <<"current count is when right got changed" << currentkcount  << std::endl;
                highestk = m-1;
                currentk = m;
            }
        }
        return currentk;
        
    }
};

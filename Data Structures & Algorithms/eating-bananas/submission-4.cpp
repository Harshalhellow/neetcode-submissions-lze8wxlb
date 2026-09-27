class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k;
        int largest=0; 
        for(int i=0; i<piles.size(); i++){
            if(piles[i]>largest) largest = piles[i];
        }
        k = largest; 
        int l = 1;
        int r = k; 
        int middle;
        int currentime=0;
        int currentbest = k; 
        while(l<=r){
            middle = (l+r)/2;
            currentime=0;
            for(int i=0; i<piles.size(); i++) currentime += (piles[i] + middle - 1) / middle;
            if(currentime>h) l = middle+1;  
            else{
                r = middle-1;  
                currentbest = middle;
            } 
        }

        return currentbest; 

    }
};

/*
total length
largets pile size  
H 
what if we found somehting that takes less than an 1 hour for the max pile it doesnt guarantee its the shortest k 


*/
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starttimes; 
        vector<int> endtimes; 
        for(int i=0; i<intervals.size(); i++){
            starttimes.push_back(intervals[i].start);
            endtimes.push_back(intervals[i].end); 
        }
        sort(starttimes.begin(),starttimes.end());
        sort(endtimes.begin(),endtimes.end());
        int meetings = 0;
        int maxcount = 0; 
        int left = 0; 
        int right = 0; 
        while(left < starttimes.size()){
            if(starttimes[left]<endtimes[right]){
                left++;
                meetings++;
            }
            else{
                right++; 
                meetings--;
            }
            if(meetings>maxcount) maxcount =meetings; 
        }

        return maxcount; 
    }
};


// we sort it 
// we go through and see if there is overlap if it is overlapped compleltely then we can obsorb it into 1 we keep going until there is no omore overlaps and then we just count how many are left 
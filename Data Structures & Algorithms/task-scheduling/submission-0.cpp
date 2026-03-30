class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> taskfreq;
        queue<pair<int,int>> cooldown;
        vector<int> frequencearray(26,0);
        for(int i=0; i<tasks.size(); i++){
            frequencearray[tasks[i]-'A']++;
        }
        for(int i=0; i<frequencearray.size(); i++){
            if(frequencearray[i]>0)taskfreq.push(frequencearray[i]);
        }
        int time = 0;
        while(taskfreq.size()!=0||cooldown.size()!=0){
            time++;
            while(cooldown.size()!=0&&cooldown.front().second==time){
                taskfreq.push(cooldown.front().first);
                cooldown.pop();
            }
            int num = -1;
            if(taskfreq.size()>0){
                num = taskfreq.top();
                num--;
                taskfreq.pop();
            }
            if(num>0) cooldown.push({num,time+n+1});

            
        }
        return time;
    }
};


// we put all elments into a prioority que its sorted by some reference to character
// 
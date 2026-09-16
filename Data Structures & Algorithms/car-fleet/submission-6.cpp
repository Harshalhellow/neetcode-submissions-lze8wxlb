class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> speedandpos(position.size()); 
        for(int i=0; i<position.size(); i++){
            speedandpos[i].first= position[i];
            speedandpos[i].second= speed[i];
        } 
        sort(speedandpos.begin(),speedandpos.end());
        stack<pair<int,float>> posandtar; 
        for(int i=0; i<position.size(); i++){
            posandtar.push({speedandpos[i].first,(float)(target-speedandpos[i].first)/speedandpos[i].second});
        }
        int counter = 0;
        pair<int,float> fleet{0,0};
        if(!posandtar.empty()){
                fleet = posandtar.top();
                counter++; 
                 posandtar.pop();
        }
        while(!posandtar.empty()){
             if(fleet.second<posandtar.top().second){
                fleet = posandtar.top();
                counter++;
             }
            posandtar.pop();
            
        }
        return counter;
    }
};

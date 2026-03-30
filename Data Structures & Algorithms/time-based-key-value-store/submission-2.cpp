class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mapOfMaps;
    TimeMap() {
     
    }
    
    void set(string key, string value, int timestamp) {
        mapOfMaps[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mapOfMaps.contains(key)){
        int left = 0;
        int right = mapOfMaps[key].size()-1;
        int mid;
        string answer;
        while(left<=right){
            mid = (left+right)/2;
            if (mapOfMaps[key][mid].first<timestamp) {
                answer = mapOfMaps[key][mid].second;
                left = mid+1;
            }
            else if(mapOfMaps[key][mid].first>timestamp) right = mid-1;
            else if (mapOfMaps[key][mid].first==timestamp) return mapOfMaps[key][mid].second;
        } 
        return answer; 
        }
        else return "";
 

    }
};


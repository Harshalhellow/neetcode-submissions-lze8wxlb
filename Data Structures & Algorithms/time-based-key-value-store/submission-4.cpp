class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> keyvalue;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyvalue[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string result; 
        int left =0;
        int right = keyvalue[key].size()-1; 
        int middle;
        while(left<=right){
            middle = (left+right)/2;
            if(keyvalue[key][middle].first==timestamp){
                result = keyvalue[key][middle].second;
                return result; 
            } 
            else if(keyvalue[key][middle].first<timestamp){
                result = keyvalue[key][middle].second;
                left = middle+1;
            }
            else right = middle-1;
        }
        return result; 
    }
};

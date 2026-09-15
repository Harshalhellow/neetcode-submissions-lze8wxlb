class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size());
        stack<int> temp,index; 
        for(int i=0; i<temperatures.size(); i++){
            while(!temp.empty()&&temperatures[i]>temp.top()){
                    temp.pop();
                    results[index.top()] = i-index.top();
                    index.pop();
                }
                temp.push(temperatures[i]);
                index.push(i);
        }
        while(!temp.empty()){
            temp.pop();
            results[index.top()] = 0;
            index.pop();
        }
        return results; 
    }
};



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> stack;
        for(int i=0; i<temperatures.size(); i++){
                while(!stack.empty() && temperatures[i]>stack.top().first){
                    result[stack.top().second] = i-stack.top().second;
                    stack.pop();
                }
                stack.push({temperatures[i],i});
        }
        return result;
    }
};

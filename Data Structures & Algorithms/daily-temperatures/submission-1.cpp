class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>answers(temperatures.size(),0);
        stack<int>unfound;
        for(int i=0; i<temperatures.size(); i++){
            while(!unfound.empty()&&temperatures[i]>temperatures[unfound.top()]){
                answers[unfound.top()] = i-unfound.top();
                unfound.pop();
            }
            unfound.push(i);
        }
        return answers;
        
    }
};

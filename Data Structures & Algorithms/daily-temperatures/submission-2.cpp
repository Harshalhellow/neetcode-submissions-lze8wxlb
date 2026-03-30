class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>answers(temperatures.size(),0);
        stack<int> hightemp;
        stack<int>index;
        for(int i=0; i<temperatures.size(); i++){
                while(!hightemp.empty() && hightemp.top()<temperatures[i] ){
                    answers[index.top()] = i-index.top();
                    index.pop();
                    hightemp.pop();
                }
                hightemp.push(temperatures[i]);
                index.push(i);
        }
        return answers; 
        
    }
};


//create a vector of all zeros 
// add elements to the stack with acoompany stack as thier index 
// if the current element is warmer than the top of the stack then figure out the difference in days for that index and update that vector correctly
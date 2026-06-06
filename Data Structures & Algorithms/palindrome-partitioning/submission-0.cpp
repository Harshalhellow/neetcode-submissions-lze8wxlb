class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answers; 
        vector<string> curr; 
        int index=0; 
        partitionhelper(answers,index,curr,s);
        return answers; 
    }
    void partitionhelper(vector<vector<string>>&answers, int index, vector<string>&curr, string& s){
        if(index==s.size()){
            answers.push_back(curr);
            return;
        } 
        for(int end = index; end<s.size(); end++){
            string temp = s.substr(index,end-index+1);
            if(ispalondone(temp)){
                curr.push_back(temp);
                partitionhelper(answers,end+1,curr,s);
                curr.pop_back();
            }
        }
    } 
    bool ispalondone(string curr){
        int left = 0; 
        int right = curr.size()-1;
        while(left<right){
            if(curr[left]==curr[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true; 
    }
};
// start at index =1 stop at the size of the size  of S
// go through and add a sub string remove it and increase the index 

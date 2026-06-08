class Solution {
public:
    vector<string> letterCombinations(string digits) {
       
        unordered_map<char,string> hash; 
        string curr; 
        vector<string> answers;
        if(digits.size()==0) return answers;
        string thestring = "abc";
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        letterCombinationshelper(digits,0,hash,answers,curr);
        return answers; 

    }

    void letterCombinationshelper(string& digits, int index, unordered_map<char,string>& hash, vector<string>&answers,string& curr){
        

        if(curr.size()==digits.size()) answers.push_back(curr);  
        if(index==digits.size()) return;

            for(int j=0; j<4; j++){
                if(j==3&& digits[index]-'0'==9){
                string temp = hash[digits[index]];
                curr.push_back(temp[j]);
                letterCombinationshelper(digits,index+1,hash,answers,curr);
                curr.pop_back(); 
                break;
                }
                if(j==3&& digits[index]-'0'!=7) break;
                string temp = hash[digits[index]];
                curr.push_back(temp[j]);
                letterCombinationshelper(digits,index+1,hash,answers,curr);
                curr.pop_back(); 
            }
        
    }
};


// we could create a hasmap of all the digits and thier characters 
// we could create a string 
// we could create a for loop that goes through each index of each characters (so repeat 3 times for each character)

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i=0; i<strs.size(); i++){
            res += to_string(strs[i].size()) + "#";
            res += strs[i]; 
        }
        return res; 
    }

    vector<string> decode(string s) {
        vector<string> res; 
        int i=0; 
        int digits = 0; 
        int num = 0;
        int startingindex = 0;
        string toadd; 
        while(i<s.size()){
            startingindex =i;
            digits = 0;
            while(s[i]!='#'){
                digits++;
                i++;
            }
            i++;
            num = stoi(s.substr(startingindex,digits));
            toadd = s.substr(i,num);
            res.push_back(toadd);
            i += num; 
        }
        return res; 
    }
};




/* the problem with my last approach is what if there is more than a 10 character string it will cause it to break;
so we need someway of telling it to stop reading 
we could just do a special character like # which tells us to stop reading; 

so when encoding we first encode how many strings then a # to stop 
then we encode how many characters 

a while loop that stops when i reaches the end;
    digits = 0 digits represents how big our number is in terms of digits; it needs to be reset to 0     evertime the while loops
    starting idex = 0 represents our starting index it will repsent what is the starting index of hte number it needs to be updated to wherever i is at the moment + 1 when the while loops
    string to add represents the string that will be created it will start with i and go all the way to digits it needs to be cleared each time the while loop resets 





*/
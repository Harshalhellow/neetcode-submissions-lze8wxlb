class Solution {
public:

    string encode(vector<string>& strs) {
        string length;
        string answer;
        for(int i=0; i<strs.size(); i++){
            length = to_string(strs[i].size())+'#';
            strs[i].insert(0,length);
            answer.append(strs[i]);
        }
        return answer;
    }

    vector<string> decode(string s) {
        vector<string>answer;
        string decodedstring;
        int index =0;
        int indexofnumber = 0;
        int numberofcharacter =0;
        while(index < s.size()){
            indexofnumber = 0;
            while(s[index+indexofnumber]!='#'){
                indexofnumber++;
            }
            numberofcharacter = stoi(s.substr(index,indexofnumber));
            index = index + indexofnumber + 1;
            decodedstring = s.substr(index,numberofcharacter);
            index += numberofcharacter;
            answer.push_back(decodedstring);
        }
        return answer;
    }
};


// we could encode a number at the start of each string saying the length of the string 
// this tells you when to stop 

// encode 
// o(m)
//o(m)


//decode
// read string then conver everynumber after each string is read
// push into vector
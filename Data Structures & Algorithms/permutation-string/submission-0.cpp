class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int>str1array(26,0);
       vector<int>str2array(26,0);
       
       for(int i=0; i<s1.size(); i++){
        str1array[s1[i]-'a']++;
       }

       for(int i=0; i<s1.size(); i++){
        str2array[s2[i]-'a']++;
       }

        if(str1array==str2array) return true; 
        int left = 0;
        int right = s1.size()-1;

        while (right<s2.size()){
            str2array[s2[left]-'a']--;
            left++;
            right++;
            str2array[s2[right]-'a']++;
            if(str1array==str2array) return  true; 
        }
        return false; 

    }
};

//creat a frequency array for str1 
// start at index 0 keep sliding window increaes frequency of array when str1 size reached compare
// then do a while loop until the end of str2 array  slide the window check if str1 and sub string of str2 frequence arrays are the same if not keep slding 


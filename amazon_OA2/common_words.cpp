class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        map<string, int> Freq;  //map for freq
        string temp = "";       //temp string for saving
        int max_count=0;
        
        for (char a : paragraph){     //for every char in para,
            if (isalpha(a)) temp += tolower(a); // if it is letter, change to lower case.
            else if(temp!=""){    // Store it if this is not letter and we have log in some char in temp
                Freq[temp]++;       //get rid of consecutive non letter case
                temp="";          //re inilizae it
            }
        }
        if (temp!="") Freq[temp]++;
        for (auto a : Freq){            //check for 
            if (a.second>max_count && find(banned.begin(),banned.end(),a.first)==banned.end()){
                max_count = a.second;
                temp=a.first;
            }
        }  
               return temp;            //if no log in we can put this out
    }
};å
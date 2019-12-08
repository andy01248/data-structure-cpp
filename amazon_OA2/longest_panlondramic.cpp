class Solution {
public:
    string longestPalindrome(string s) {
        
        int start = 0; //start index of palindrome
        int  max = 0;   //the max length of palindrome
        int  sub_len;   //the length of sub_string
        string res; //the result string
        if(s.empty()) return {};
        int len =s.length();
        int table[len][len];
        //bool table[len][len]={false};
        memset(table,0,sizeof(int)*len*len);
        //start to fill the single character. every single character is palindromic substring
        for (int i=0; i<len;i++) table[i][i]=1;
        max=1; //max lendth change to 1       
        //start to check the 2 characters case. SInce 2 char case dont have sub-string inside
        for (int i=0; i<len-1;i++){
            if (s[i+1]==s[i]) {
                table[i][i+1]=1;
                start=i;
                max=2;
            }
        }
        int R; //the end point of substring
        //Check the rest cases until substring length = string length
        for (sub_len=3; sub_len<=len;sub_len++ ){    //the different string length
            for (int L=0; L<=len-sub_len;L++){  //the start point of substring
                R = L+sub_len-1;  //the right side if substring
                if (table[L+1][R-1]==1 && s[L]==s[R]){
                    table[L][R]=1;
                    start=L;
                    max=sub_len;   
                }               
            }
        }           
        res = s.substr(start,max);
        return res;        
    }
};
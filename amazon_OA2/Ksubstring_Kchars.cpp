#include<iostream>
#include <string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

class solution{
    public:
    vector<string>KSubString(string s, int K){
        vector<string> shabi;
        shabi.push_back("shabi");
        if ( s.empty()==1 || K==0) return shabi;
        map<char,int> table;
        vector<string> res;
        set<string> temp;
        int start =0;  //the sliding window start point
        // for (int i = 0; i<s.size();i++){
        //     table[s[i]]++;
        //     while (table[s[i]]>1 && (i>=start)){
        //         table[s[start]]--;
        //         start++;    //slide the window to duplicate 
        //     }
        //     if( i-start+1 == K){
        //         temp.insert(s.substr(start,K));
        //         table[s[start]]--;
        //         start++;
        //     }
        // }
        for (int i = 0; i<s.size();i++){
            if (table.find(s[i])!=table.end()  && (table[s[i]]>=start)){
                start=table[s[i]]+1;    //slide the window to after previous dupulate 
            }
                table[s[i]]=i;
            if( i-start+1 == K){
                temp.insert(s.substr(start,K));
                start++;
            }
        }
        res.assign(temp.begin(),temp.end());
        return res;

    }
};


int main(){
 
 string input;
 int k = 2;
 input="abcabc";
 solution answer;
 vector<string> output = answer.KSubString(input,k);
//  for (string a : output){
for (int i=0; i<output.size();i++){

     cout<<output[i]<<endl;
 }

}
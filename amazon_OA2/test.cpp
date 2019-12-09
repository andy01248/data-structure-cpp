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
        //if(s.empty() || K==0) return {};
        map<char,int> table;
        set<string> temp;
        vector<string> res;
        int left = 0;

        for (int i=0; i<s.length();i++)
        {
            if(table.count(s[i] && table[s[i]]>left)){
                left=table[s[i]]+1;

            }
            table[s[i]]=i;
            if(i-left+1 ==K){
                temp.insert(s.substr(left,K));
                left++;
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
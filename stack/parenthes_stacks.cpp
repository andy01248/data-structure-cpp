#include <iostream>
#include<stack>
using namespace std;
#define MAX_SIZE 50

bool Check_Bracket_balanced(char *string, int length){
    stack<char> S;
    for (int i =0; i<length; i++){
        if (string[i]=='(' || string[i]=='[' || string[i]=='{'){
                S.push(string[i]);
        }
        else if(string[i]==')' || string[i]==']' || string[i]=='}'){
            if (S.empty() || (string[i]-S.top()!=1 && string[i]-S.top()!=2)){
                return false; break;
            }
            else{
                S.pop();
            }
        }
    }
    return S.empty() ? true:false;
}
int main(){
    char string[MAX_SIZE];
    cout<<"Please insert the string: ";
    cin>>string;
    if (Check_Bracket_balanced(string,strlen(string))) cout<<"balanced bracket input";
    else cout<<"wrong balanced bracket";
}

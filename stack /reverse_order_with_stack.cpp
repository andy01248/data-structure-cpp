#include <iostream>
#include<stack>
using namespace std;

void ReverseString(char *C, int length){
    stack<char> S; //create a stack with character type
    //Loop for push
    for (int i=0; i<length;i++){
        S.push(C[i]);
    }
    //loop for pop
    for (int i=0; i<length;i++){
        C[i] = S.top();
        S.pop();
    }
}

int main(){
char C[51];
cout<<"Enter a string\n";
cin>>C;
ReverseString(C,strlen(C));
cout<<C;
//The most efficient way to swap the string is to swap the first and last item and keep increasing/decreasing the index in the begining and end/

}
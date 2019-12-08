#include<iostream>
#include <string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int a[6]={0,1,2,3,4,5};
    int i=2;
    cout<<" i=" <<i<<" "<<a[i++]--<<" i=" <<i<<endl;
    cout<<" i=" <<i<<" " <<a[i++]<<" i=" <<i<<endl;
    cout<<" i=" <<i<<" "<<a[++i]<<" i=" <<i<<endl;
    cout<<a[2]<<a[3];

    }



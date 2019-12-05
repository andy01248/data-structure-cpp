#include <iostream>
#include<queue>
using namespace std;

void print(priority_queue <int> array){

    priority_queue<int> temp = array;
    while (!temp.empty()){
    cout<<temp.top()<<"\n";
    temp.pop();
    }


}
int main(){
    priority_queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(5);
    print(Q);
    Q.pop();
    print(Q);

    int a;

    a=27/10;
    cout<<a;

}
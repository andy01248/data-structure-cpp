// Binary search Tree implementation

#include <iostream>

using namespace std;

int main(){
int *p= new int;
*p=5;
cout<<p<<endl;
cout<<*p<<endl;
delete p;

//start address of p is stored in stack
//But the 10 int memory is dynamiclly store in heap
int *q = new int[10];
q[0]=1;
q[1]=2;
delete [] q;

return 0;
};

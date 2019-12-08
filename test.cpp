// Binary search Tree implementation

#include <iostream>
#include<map>
#include<vector>
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

int a[5]={6,7,8,9,10};
for (int i :a){
    if (i > 7) cout<<i<<" ";
    else if (i>8) cout<<i<<" ";
}

map<char,int> M;
M['a']=1;
M['a']=2;
M['c']=3;
M['']=1;
cout<<M.count(4)<<" ";
cout<<M.find(4)->second<<" ";
cout<<(M.find(4)==M.end())<<" ";


vector<int> vec;

cout << count(vec.begin(),vec.end(),8)<<"";
cout<< (find(vec.begin(),vec.end(),8)==vec.end())<<"";




};

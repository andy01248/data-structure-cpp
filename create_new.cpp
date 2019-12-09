#include<iostream>
#include <string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main(){
// int char array 2d array
int a;
int *b;
char c;
char *d;
int e[5]; //declare with specific type
char f[5];
int g[5]={1,2,3,4,5};//declare with spcific numbers and values
char h[5]={'a','b','c','d','e'};
int i[]={1,2,3,4,5}; //declare with initializing lements
int j[2][3]={{1,2,3},{2,3,4}};
int k[][3]={{1,2,3},{2,3,4}}; //first [] is row, second[] is column 

//dynamic memory 1d 2d array int
int **p = new int*[5]; //create a point to array with size 5
for(int i=0; i<5;i++){
    p[i]= new int[6];    //for each position of previous array, create a new point to array with size 6
}   //dynamic 2d array with p[5][6]  a array of pointers to your arrays. 
p[2][3]=5;
cout<<p[2][3]*p[2][3]<<"Dddd";
vector< pair<int,int> > vec1;
vec1.push_back(make_pair(p[2][3],p[2][4]));
cout<<vec1[0].first;

for(int i=0;i<5;i++){
    delete[] p[i];  //delete p[][] first
}
delete[] p; //delete p[]
int* n = new int;
delete(n);
int* o= new int[10]; //allocate a block of memory and o is the start point memory
delete[] o;

//stack queue string  priority queue heap
stack<int> S;   //top      push pop
queue<int> Q;   //front    push pop
string R;
priority_queue<int> Y;  //max heap  //top  push pop 
priority_queue<int, vector<int>, greater<int> > Z; //min heap  //top  push pop 

string AA;
AA.empty();


        map<int,int> windowL;
windowL[5]++;
cout<<windowL[5]<<" asdf";
//map set
map<int,int> M;
// M['b']=7;
M[5]=5;
M[6]=6;
M[4]=4;
M[3]=3;
for (auto iter = M.rbegin();iter!= M.rend();iter++)
{
cout<< "aaa"<<iter->second;
}
// M.insert(pair<char,int>('c',8));  //insert
// M.erase('b');
//cout<<M['b'];
map<char,int>::iterator itr; //iterator to search in map
M.upper_bound('c'); //return the next element just great than chosen key. If no more greater key, return the number of element in map and 0
M.lower_bound('c'); //return the exact key if key exist. If key not exist, return the next greater key. If no next greater key, return number of elememt and 0 
// M.end() and T.end() is the address of next postion of last element.
set<int> T;
T.insert(10);
T.insert(20);
T.insert(15);
set<int>::iterator iter;
for( iter=T.begin();iter!=T.end();iter++){
    cout<<*iter;
}
if (T.find(16)==T.end()){
    cout<<"no such element";
}

//vector

vector<int> v1 (6,0) ; //1d vector with size 3
v1.push_back(7);
v1.push_back(8);
cout<<"the index of 7 is "<< find(v1.begin(),v1.end(),7)-v1.begin()<<endl;
cout<<"the index of 7 is "<< distance(v1.begin(),find(v1.begin(),v1.end(),7))<<endl;

vector<vector<int> > v4  (10, vector<int> (5,0));//create 10 row with each row a vector with 5 elements with all 0
vector<vector<int> > v5  (10, vector<int> (5,1));
v5[0] = v4[0];
cout<<v5[0][0]<<v5[2][1]<<" bbbb"<<endl;
//v1[0]=7;

cout<<find(v1.begin(),v1.end(),7)-v1.begin()<<"  aaaaaa ";

make_heap(v1.begin(),v1.end()); //make vector as heap
sort_heap(v1.begin(),v1.end()); //sort heap and make it not the heap
for (int i=0; i<v1.size() ; i++){
    cout<<v1[i]<<' ';
}
vector< vector<string> > v2 (5); //2d vector with 5 rows

v2[0].push_back("a1");
v2[0].push_back(" 2");
v2[1].push_back("asd");
for (int i=0;i<v2.size();i++){
    for (int j=0;j<v2[i].size();j++){
        cout<<v2[i][j]<<' ';
    }
    cout<<endl;
}
cout << v2.size();
// string x: v2[i] for string x in v2[i]
// for (int i=0;i<v2.size();i++){
//     for (string x : v2[i]){
//         cout<<x<<' ';
//     }
//     cout<<endl;
// }


}



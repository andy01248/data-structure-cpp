#include <iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<iterator>
// #include<vector>
using namespace std;

int main(){

map <char,int> table;  //hash table key -> char , values -> int
table['a']=6;  //insert
table['b']=7;
table.insert(pair<char,int>('c',8));  //insdert
table.insert(pair<char,int>('d',10));
table['a']=1;
map<char,int>::iterator iter; //iter for map address

for ( iter=table.begin();iter!=table.end();iter++){
    cout<<iter->first<<' '<<iter->second;
}
iter = table.find('a'); //find function in map. if not found, iterator -> table.end()
if(iter==table.end()){   //.end() give the next to last element in the table.usually used to show nothing
    cout<<"not in the map";
}
else cout<<iter->first<<' '<< iter->second;



};


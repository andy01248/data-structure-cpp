// Binary search Tree implementation

#include <iostream>
#include<map>
#include<vector>
using namespace std;

using namespace std;
vector<pair<int, int> > closestLocations(int totalCrates, int** allLocations,
                                         int truckCapacity)
{
   // if (truckCapacity<totalCrates) return ; //show constrints
    vector< pair <int,int > > res ;    //initialize result vector
    vector<int> dist ; //initialize distance vector with all 0. totalcartes elements
    
    for (int i =0; i<totalCrates; i++){   //calculate the distance ^2 to truck
        dist.push_back(allLocations[i][0]*allLocations[i][0] + allLocations[i][1]*allLocations[i][1]);
    }
    sort(dist.begin(),dist.end());         // sort the dist ascendingly
    int threshold = dist[truckCapacity-1]; // find the truckCapacity elements weight
    int index=0;                           //index for counting
    for (int i=0; i<totalCrates; i++){
        if ( allLocations[i][0]*allLocations[i][0] + allLocations[i][1]*allLocations[i][1] <= threshold){
            res.push_back(make_pair(allLocations[i][0],allLocations[i][1]));
            int a=5;
        }
    }
    return res;
}

int main(){
int totalCrates=3;
int truckCapacity=2;
int **p = new int*[3]; //create a point to array with size 5
for(int i=0; i<3;i++){
    p[i]= new int[2];    //for each position of previous array, create a new point to array with size 6
} 
p[0][0]=1;
p[0][1]=2;
p[1][0]=4;
p[1][1]=5;
p[2][0]=3;
p[2][1]=2;
vector< pair<int,int> > vec1;
vec1 = closestLocations(totalCrates,p,truckCapacity);
cout<<vec1[0].first;
cout<<vec1[0].second;
cout<<vec1[1].first;
cout<<vec1[1].second;

}
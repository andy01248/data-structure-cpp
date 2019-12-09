//Given a list of positive integers nums and an int target, return indices of the two numbers such that they add up to a target - 30.

// Conditions:

// You will pick exactly 2 numbers.
// You cannot pick the same element twice.
// If you have muliple pairs, select the pair with the largest number.
//if no pair, output the pair with largest number

#include <iostream>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        target-=30;
        int flag=0; //to show there is result
        map<int,int> Map;
        int Large=0; //note down the largest element
        vector<int> res (2,0);
        if (nums.empty()) return res;

        //vector<int> res ;
        for (int i=0; i<nums.size();i++){
            if (!Map.count(nums[i])) Map[target - nums[i]]=i;
            else{
                if (Large<max(nums[i],target-nums[i])){
                    // res.push_back(Map[nums[i]]);
                    // res.push_back(i);
                    res[0]=(Map[nums[i]]);
                    res[1]=i;
                    Large=max(nums[i],target-nums[i]);
                    flag=1;
                }

            }         
        }
        if (flag ==1) return res;
        else if (nums.size()>1){
            sort(nums.begin(),nums.end());
            res[0]=Map[target-nums.rbegin()[0]];  //put the largest element pair
            res[1]=Map[target-nums.rbegin()[1]]; // output the larget elmemt pair
        }
         return res;
    }

vector<int> movie(vector<int>& nums, int target) {
        int flag=0; //to show there is result
        vector<int> Mlength = nums;
        sort(Mlength.begin(),Mlength.end());

        int MAX=INT_MIN; //note down the largest element
        vector<int> temp(2,0);
        vector<int> res (2,0);
        if (nums.empty()) return res;

        //vector<int> res ;
        for (int i=Mlength.size()-1; i>-1;i--){
            for (int j=0;j<i;j++){
                if (Mlength[i]+Mlength[j]<=target){
                    if (Mlength[i]+Mlength[j]>MAX){
                        MAX=Mlength[i]+Mlength[j];
                        temp[0]=Mlength[i];
                        temp[1]=Mlength[j];
                        flag=1;
                    }
                }
                else break;
            }      
        }
            if(flag==1){
                //cout<<temp[0]<<temp[1]<<endl;
                res[0]=find(nums.begin(),nums.end(),temp[0])-nums.begin();
                res[1]=find(nums.begin(),nums.end(),temp[1])-nums.begin();            
            }
            else{

                res[0]=find(nums.begin(),nums.end(),Mlength[Mlength.size()-1])-nums.begin();
                res[1]=find(nums.begin(),nums.end(),Mlength[Mlength.size()-2])-nums.begin();   
            }
         return res;
    }


};

int main(){
    int a[6]=   {20, 50, 40, 25, 30, 10};
    vector<int> nums (6,0);
    vector<int> nums1 (1,0);

    for (int i=0; i<nums.size();i++){
        nums[i]=a[i];
    }
    int k = 50;
    Solution myclass;
    vector<int> res = myclass.movie(nums,k);

        for (int i=0; i<res.size();i++){
            cout<<res[i]<<endl;
    }

    // int c[7][2];
    
    // cout<<c[0][2];
    // cout<<sizeof(c);
    // string ab ="abcdef";
    // string abc=ab.substr(0,3);
    // cout<<abc;

}

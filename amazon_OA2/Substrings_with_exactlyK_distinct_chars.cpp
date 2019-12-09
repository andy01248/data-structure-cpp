class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res=0;
        map<int,int> windowL;
        map<int,int> windowS;
        int leftL =0, leftS=0, distL=0, distS=0;
        
        for(int i =0; i<A.size();i++){
            windowL[A[i]]++;
            windowS[A[i]]++;
            if (windowL[A[i]]==1) distL++;
            if (windowS[A[i]]==1) distS++;
            
            while(distL>K){
                windowL[A[leftL]]--;
                if (windowL[A[leftL]]==0) distL--;
                leftL++;
            }
            while(distS>=K){
                windowS[A[leftS]]--;
                if (windowS[A[leftS]]==0) distS--;
                leftS++;
            }
           
            res+= leftS-leftL;
            
        }
        return res;
    }
};
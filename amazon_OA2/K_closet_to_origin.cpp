class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.size()<K) return {};
        vector<vector<int>> res (K, vector<int>(2,0));
        vector<double> dist (points.size(),0);
        for (int i = 0; i<points.size();i++){
            dist[i] = pow(points[i][0],2)+pow(points[i][1],2);
        }
        sort(dist.begin(),dist.end());
        int threshold = dist[K-1];
        int index=0;
        for (int i =0; i<points.size();i++){
            if ( pow(points[i][0],2)+pow(points[i][1],2) <=threshold){
                res[index++] = points[i];
            }            
        }
        return res;
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //DP
        int i =0, j =0; //grid index
        if(grid.size()==0) return 0;
        for (i=0; i<grid.size();i++){
            for (j=0; j<grid[0].size();j++){
                if (i==0 && j>=1) grid[i][j] += grid[i][j-1];
                else if(j==0 && i>=1) grid[i][j] += grid[i-1][j];
                else if(i>=1 && j>=1) grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
            }
        }          
        return grid[grid.size()-1][grid[0].size()-1];
    }           
};
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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int r = grid.size();
        int c = grid[0].size();
        for (int i=1;i<r;i++) grid[i][0]+=grid[i-1][0];
        for (int j=1;j<c;j++) grid[0][j]+=grid[0][j-1];
        for (int i=1;i<r;i++){
            for (int j=1;j<c;j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[r-1][c-1];
    }           
};
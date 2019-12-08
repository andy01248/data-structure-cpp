//dfs method

class Solution {
public:
            int min_sum=INT_MAX;

    int minPathSum(vector<vector<int>>& grid) {
        //DFS
        int i =0, j =0; //grid index
        if(grid.size()==0) return 0;
        int sum =0;
        DFS_sum(grid,i,j,sum);
        return min_sum;
    }        
    void DFS_sum(vector<vector<int>>& grid,int i,int j,int sum){
        if (i>=grid.size() || j>=grid[0].size()) return;
        if (i==grid.size()-1 && j==grid[0].size()-1){
            sum += grid[i][j];
            min_sum=min(sum,min_sum);
            return;
        }
        sum+=grid[i][j];
        DFS_sum( grid,i,j+1,sum);
        DFS_sum( grid,i+1,j,sum);
    }    
};

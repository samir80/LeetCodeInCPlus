class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp;
        int gridColSize = grid[0].size();
        int gridRowSize = grid.size();
        int i,j;
        
        dp.push_back(grid[0][0]);
        for(j = 1; j< gridColSize; j++){
            dp.push_back(dp[j-1] + grid[0][j]);
        }
        for(i =1; i<gridRowSize; i++){
            for(j = 0; j < gridColSize; j++){
                if(j == 0)
                    dp[j] += grid[i][j];
                else
                    dp[j] = dp[j-1] < dp[j] ? (dp[j-1] + grid[i][j]):(dp[j]+grid[i][j]);
            }
        }
        return dp[gridColSize-1];
    }
 /*   
 int minPathSumWithDP(int** grid, int gridRowSize, int gridColSize){
        int *dp;
        int i,j;
        dp = (int*)malloc(sizeof(int)*gridColSize);
        if ( NULL == dp)
            return -1;
        
        dp[0] = grid[0][0];
        for(j = 1; j< gridColSize; j++){
            dp[j] = dp[j-1] + grid[0][j];
        }
        
        for(i =1; i<gridRowSize; i++){
            for(j = 0; j < gridColSize; j++){
                if(j == 0)
                    dp[j] += grid[i][j];
                else
                    dp[j] = dp[j-1] < d[j] ? (dp[j-1] + grid[i][j]):(dp[j]+grid[i][j]);
            }
        }
        
        return dp[gridColSize-1];
    }
*/    

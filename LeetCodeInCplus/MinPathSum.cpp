typedef struct State
{
    int x,y;
    int path;
}State;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        State mState = { 
            .x=0,
            .y=0,
            .path=grid[0][0]
        };
        BackTrace(grid,mState);
        return mMinPath;
    }
    
    void BackTrace(vector<vector<int>>& grid, State& mState){
            if(mState.y >= grid.size() || mState.x >= grid[mState.y].size())
                return;
            if(mState.y == grid.size()-1 && mState.x == grid[mState.y].size()-1){
                mMinPath == -1 ? mMinPath = mState.path :  mMinPath > mState.path? mMinPath = mState.path:0;
            }
            if (mState.x  < grid[mState.y].size() - 1) {
                mState.x++;
                mState.path += grid[mState.y][mState.x];
                BackTrace(grid,mState);
                mState.path -= grid[mState.y][mState.x];
                mState.x--;
            }
            
            if (mState.y < grid.size() - 1) {
                mState.y++;
                mState.path += grid[mState.y][mState.x];
                BackTrace(grid,mState);
                mState.path -= grid[mState.y][mState.x];
                mState.y--;
            }
    }
    
    Solution():mMinPath(-1){
        
    }
    int mMinPath;
};

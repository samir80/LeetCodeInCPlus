class Solution {
public:
    int climbStairs(int n) {
        if (n == 0){
            return 1;
        }
        int sum = 0;
        for(int step_index =0; step_index < 2; step_index++ ){
            if( step[step_index] <= n ){
                sum +=  memoStep[n - step[step_index]] == -1 ? climbStairs(n - step[step_index]) : memoStep[n - step[step_index]];
            }
                
        }
        memoStep[n] = sum;
        return sum;
    }
    
    static int step[2];
    int memoStep[1000];
    
    Solution(){
        for(int i = 0;i < 1000; i++)
            memoStep[i] = -1;
    }
};

    int Solution::step[2] = { 1, 2 };

/*
                    Climb  stair
    You are climbing a stair case. It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Note: Given n will be a positive integer.
    Example:
    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0){
            return 1;
        }
        int sum = 0;
        for(int step_index =0; step_index < 2; step_index++ ){
            if( step[step_index] <= n )
                sum += climbStairs(n - step[step_index]);
        }
        return sum;
    }
    
    static int step[2];
};

    int Solution::step[2] = { 1, 2 };

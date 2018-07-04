class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int nLen = nums.size();
        for(int i = 0; i < nLen; i++ )
            res ^= nums[i];
        return res;
    }
};

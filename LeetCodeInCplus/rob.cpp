class Solution {
public:
    int rob(vector<int>& nums) {
        int nLen = nums.size();
        if (nLen == 0)
            return 0;
        if (nLen == 1)
            return nums[0];
        int nPreSub1 = nums[nLen - 1];
        int nPreSub2 = 0;
        for (int i = nLen - 2; i >= 0; i--) {
            int nCurrentMax = nums[i] + nPreSub2 > nPreSub1? nums[i] + nPreSub2 : nPreSub1;
            nPreSub2 = nPreSub1;
            nPreSub1 = nCurrentMax;
        }
        return nPreSub1;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nLen =nums.size();
        if(nLen <= 1 || k<=0)
            return;
        int nReal_k = k % nLen;
        if(nReal_k == 0)
            return;
        reverse(nums.begin(), nums.begin() + nLen - nReal_k);
        reverse(nums.begin()+nLen-nReal_k,nums.end());
        reverse(nums.begin(), nums.end());
    }
};

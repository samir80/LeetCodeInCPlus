class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nRet = 0;
        for(int i = 0; i < 32; i++){
            int nCount = 0;
            for(int j =0 ; j < nums.size(); j++){
                nCount += (nums[j] >> i) & 0x1;
            }
            nRet += (nCount%3) << i;
        }
        
        return nRet;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nLen = nums.size();
        if(nLen == 1)
            return nums[0];
        int nLargest = nums[nLen-1];
        int nPreLargest = nLargest;
        for(int i = nLen-2; i >= 0; i--){
            if(nPreLargest >= 0){
                nPreLargest = nPreLargest + nums[i];
            }else{
                nPreLargest = nums[i];
            }
            if(nPreLargest > nLargest)
                nLargest = nPreLargest;
        }
        return nLargest;
    }
};

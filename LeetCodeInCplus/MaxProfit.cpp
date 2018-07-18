class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nLen = prices.size();
        if(nLen == 0)
            return 0;
        int nBestSellPrice = prices[nLen - 1];
        int nMaxProfit = 0;
    
        for (int i = nLen - 2; i >= 0; i--) {
            if (prices[i] < nBestSellPrice) {
                if (nBestSellPrice - prices[i] > nMaxProfit)
                    nMaxProfit = nBestSellPrice - prices[i];
            }
            else {
                nBestSellPrice = prices[i];
            }
        }
        return nMaxProfit;
    }
};

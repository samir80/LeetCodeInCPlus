// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //binary query
        int nLowIdx = 1;
        int nHighIdx = n;
        int nMidIdx = 0;
        while (nLowIdx <= nHighIdx) {
            nMidIdx = (nHighIdx + nLowIdx) / 2;
            if (isBadVersion(nMidIdx)) {
                if (nMidIdx <= 1 || !isBadVersion(nMidIdx - 1)) {
                    return nMidIdx;
                }
                else {
                    //keep searching the left part
                    nHighIdx = nMidIdx - 1;
                }
            }
            else {
                if (nMidIdx < n && isBadVersion(nMidIdx + 1)) {
                    return nMidIdx+1;
                }
                else {
                    //keep searching the right part
                    nLowIdx = nMidIdx + 1;
                }
            }
        }
        return -1;
    }
};

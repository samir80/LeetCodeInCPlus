class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        vecNums.clear();
    }
    
    void addNum(int num) {
     //   vecNums.push_back(num);
        int pos = findPosition(num);
        vecNums.insert(vecNums.begin()+pos,num);
    }
    
    double findMedian() {
        int nsize = vecNums.size();
        if(nsize == 0)
            return -1;
        if(nsize % 2 == 0){
            return (vecNums[nsize/2-1]+vecNums[nsize/2])/2.0;
        }else{
            return vecNums[floor(nsize/2.0)];
        }
    }
    
    int findPosition(int num){
        int pos = 0;
        int nsize = vecNums.size();
        if(nsize == 0)
            return pos;
        int low = 0;
        int high = nsize -1;
        int middle = (low + high)/2;
        while(low <= high){
            if(vecNums[middle] == num){
                pos = middle;
                break;
            }else if(vecNums[middle] > num){
                high = middle -1;
                middle = (low + high)/2;
                pos = low;
            }else{
                low = middle + 1;
                middle = (low + high)/2;
                pos = high + 1;
            }
        }
        return pos;
        
    }
    vector<int> vecNums;
};

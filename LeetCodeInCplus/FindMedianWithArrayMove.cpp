class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        nsize = 0;
    }
    
    void addNum(int num) {
        int i = nsize -1;   
        while(i >= 0 && vecNums[i] > num){
            vecNums[i+1] = vecNums[i];
            i--;
        }
        vecNums[++i] = num;
        nsize ++;
    }
    
    double findMedian() {
        if(nsize == 0)
            return -1;
        if(nsize % 2 == 0){
            return (vecNums[nsize/2-1]+vecNums[nsize/2])/2.0;
        }else{
            return vecNums[nsize/2];
        }
    }
    
    int  vecNums[10000000];
    int  nsize;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

class MedianFinder {
public:
    void addNum(int num) {
       
        
        if((minHeap.size()+maxHeap.size())&0x01){//奇数时插入大顶堆
            if(minHeap.size() > 0 && minHeap[0] < num){
                minHeap.push_back(num);
                push_heap(minHeap.begin(),minHeap.end(),greater<int>());
                num = minHeap[0];

                pop_heap(minHeap.begin(),minHeap.end(),greater<int>());
                minHeap.pop_back();
            }
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(),maxHeap.end(),less<int>());

        }
        else{//偶数时插入小顶堆
            if(maxHeap.size() > 0&& maxHeap[0] > num){
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(),maxHeap.end(),less<int>());

                num = maxHeap[0];

                pop_heap(maxHeap.begin(),maxHeap.end(),less<int>());
                maxHeap.pop_back();
            }
            minHeap.push_back(num);
            push_heap(minHeap.begin(),minHeap.end(),greater<int>());
        }
    }
    
    double findMedian() {
        int size = minHeap.size() + maxHeap.size();
        if(size <= 0) return -1;
        double result=0.0;
        if(size & 0x01) 
            result = minHeap[0];
        else 
            result = (minHeap[0]+maxHeap[0])/2.0;

        return result;
    }
    
    vector<int> minHeap;
    vector<int> maxHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

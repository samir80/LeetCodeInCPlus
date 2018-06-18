class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        
        while(j < n){
            if(i >= m){
                for(;j<n;j++,i++)
                    nums1[i] = nums2[j];
                return;
            }
            if(nums1[i] > nums2[j]){
                nums1.insert(nums1.begin()+i,nums2[j]);
                nums1.pop_back();
                i++;m++;
                j++;
            }else{
                i++;
            }
            
        }
        
    }
};

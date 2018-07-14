class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    /*    for(int i = 0; i < nums.size(); i++ ){
            int nRemain = target - nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(j == i)
                    continue;
                if(nRemain == nums[j]){
                    vector<int> vecRet;
                    vecRet.push_back(i);
                    vecRet.push_back(j);
                    return vecRet;
                }
            }       
        }
    */
        /*
            search use hash,just O(1) complexity
        */
        vector<int> vecRet;
        map<int, int> mapRemains;
        int nLen = nums.size();
        for(int i = 0; i < nLen; i++){
            mapRemains.insert(pair<int, int>(target - nums[i], i));
        }
        map<int, int>::iterator it;
        for(int i = 0; i < nLen; i++){
            if((it=mapRemains.find(nums[i]))!= mapRemains.end() && it->second != i){
                vecRet.push_back(i);
                vecRet.push_back(it->second);
                return vecRet;
            }
        }
        
    }
};

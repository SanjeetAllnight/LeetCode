class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int spmm=0;
        int i=1;
        while(true){
            if(i%k==0 && find(nums.begin(), nums.end(), i) == nums.end()){
                spmm=i;
                break;
            }
            i++;
        }    
        return spmm;
    }
};
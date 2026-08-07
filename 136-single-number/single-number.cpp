class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k=0;
        for(int n:nums){
            k^=n;
        }
        return k;
    }
};
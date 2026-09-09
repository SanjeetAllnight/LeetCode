class Solution {
public:
    long long countCommas(long long n) {
        long curr=1000,res=0;
        while(curr<=n){
            res+=n-curr+1;
            curr*=1000;
        }
        return res;
    }
};
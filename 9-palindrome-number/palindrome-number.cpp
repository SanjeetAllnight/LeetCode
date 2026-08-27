class Solution {
public:
    bool isPalindrome(int x) {
        long og=x;
        long r=0;
        while(x>0){
            int d=x%10;
            r=r*10+d;
            x=x/10;
        }
        if(r==og){
            return true;
        }
        return false;
    }
};
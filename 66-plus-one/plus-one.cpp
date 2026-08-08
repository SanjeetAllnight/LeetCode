class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        while(i>=0){
            if(digits[i]==9){
                if (i==0){
                    digits[i]=1;
                    digits.push_back(0);
                    return digits;
                }
                digits[i]=0;
                i--;
            }
            else{
                digits[i]+=1;
                return digits;
            }
        }
        return digits;
    }
};
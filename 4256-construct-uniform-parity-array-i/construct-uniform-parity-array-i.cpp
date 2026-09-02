class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0;
        for (int x : nums1) {
            if (x % 2 == 1) oddCount++;
        }
        bool canMakeEven = (oddCount != 1);
        bool canMakeOdd = (oddCount >= 1);
        return canMakeEven || canMakeOdd;
    }
};
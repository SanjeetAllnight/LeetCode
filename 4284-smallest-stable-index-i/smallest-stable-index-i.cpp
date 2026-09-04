class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> frontMax(n);
        vector<int> backMin(n);
        frontMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            frontMax[i] = max(frontMax[i-1], nums[i]);
        }
        backMin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            backMin[i] = min(backMin[i+1], nums[i]);
        }
        int instabilityScore = 0;
        for (int i = 0; i < n; i++) {
            instabilityScore = frontMax[i] - backMin[i];
            if (instabilityScore <= k) {
                return i;
            }
        }
        return -1;
    }
};
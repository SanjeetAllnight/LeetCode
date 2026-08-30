class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        int lo = min(minIdx, maxIdx);
        int hi = max(minIdx, maxIdx);
        int fromFront = hi + 1;
        int fromBack = (nums.size() - lo);
        int fromBoth = (lo + 1) + (nums.size() - hi);
        return min({fromFront, fromBack, fromBoth});
        
    }
};
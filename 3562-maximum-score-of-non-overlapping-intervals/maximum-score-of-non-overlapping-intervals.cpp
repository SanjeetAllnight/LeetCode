class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b){ return intervals[a][1] < intervals[b][1]; });
        vector<long long> L(n+1), R(n+1), W(n+1);
        vector<int> idxOf(n+1);
        for (int i = 1; i <= n; i++) {
            int o = order[i-1];
            L[i] = intervals[o][0];
            R[i] = intervals[o][1];
            W[i] = intervals[o][2];
            idxOf[i] = o;
        }
        struct State { long long w; vector<int> idx; };
        auto better = [](const State& a, const State& b) -> bool {
            if (a.w != b.w) return a.w > b.w;
            size_t m = min(a.idx.size(), b.idx.size());
            for (size_t i = 0; i < m; i++) {
                if (a.idx[i] != b.idx[i]) return a.idx[i] < b.idx[i];
            }
            return a.idx.size() < b.idx.size();
        };
        vector<vector<State>> dp(n+1, vector<State>(5));
        for (int k = 0; k <= 4; k++) dp[0][k] = {0, {}};
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i-1][k];
                if (k >= 1) {
                    int lo = 1, hi = i-1, p = 0;
                    while (lo <= hi) {
                        int mid = (lo+hi)/2;
                        if (R[mid] < L[i]) { p = mid; lo = mid+1; }
                        else hi = mid-1;
                    }
                    State cand = dp[p][k-1];
                    cand.w += W[i];
                    cand.idx.push_back(idxOf[i]);
                    sort(cand.idx.begin(), cand.idx.end());
                    if (better(cand, dp[i][k])) dp[i][k] = cand;
                }
            }
        }
        return dp[n][4].idx;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, best = 1;
        for (int c = 0; c < n; c++) {
            for (int k = 0; k < 2; k++) {
                int l = c, r = c + k;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }
                int len = r - l - 1;
                if (len > best) {
                    best = len;
                    start = l + 1;
                }
            }
        }
        return s.substr(start, best);
    }
};
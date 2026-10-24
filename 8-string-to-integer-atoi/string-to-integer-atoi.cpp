class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1, res = 0;
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            int d = s[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && d > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + d;
            i++;
        }
        return res * sign;
    }
};
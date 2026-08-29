class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double n = x;
        while (abs(n * n - x) > 0.000001) {
            n = 0.5 * (n + x / n);
        }
        return (int)n;
    }
};
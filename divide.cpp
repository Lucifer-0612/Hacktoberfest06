class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Determine sign of result
        bool sign = (dividend >= 0) == (divisor >= 0);

        // Work with positive numbers
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        while (n >= d) {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        quotient = sign ? quotient : -quotient;

        // Clamp to INT_MIN, INT_MAX
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;
        return quotient;
    }
};

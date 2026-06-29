class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        int isNegative = (x < 0) ? -1 : 1;
        long long num = abs(x);

        while (num > 0) {
            int y = num % 10;
            result = result * 10 + y;
            num /= 10;
        }

        if (abs(result) > pow(2, 31) - 1) {
            return 0;
        }

        return result * isNegative;

    }
};

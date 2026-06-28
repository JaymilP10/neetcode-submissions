class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        for (int i = 0; i < 32; i++) {
            int y = n >> i;
            if (y & 1 == 1) {
                x++;
            }
        }

        return x;
    }
};

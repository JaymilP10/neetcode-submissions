class Solution {
public:
    int getSum(int a, int b) {
        uint32_t one = a;
        uint32_t two = b;
        uint32_t output = 0;

        int carry = 0;

        for (int i = 0; i < 32; i++) {
            uint32_t bitA = (one >> i) & 1;
            uint32_t bitB = (two >> i) & 1;
            uint32_t result = bitA ^ bitB ^ carry;
            carry = (bitA & bitB) | (carry & (bitA | bitB));
            output = output | result << i;
        }

        return output;
        

    }
};

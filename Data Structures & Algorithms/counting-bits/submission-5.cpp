class Solution {
public:
    vector<int> countBits(int n) {
        int count = 0;
        vector<int> output(n+1);
        output[0] = 0;
        // output[1] = 1;
        // output[2] = 1;
        // output[3] = 2;
        // output[4] = 1;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                output[i] = output[i / 2];
            } else {
                if (i / 2 >= 1) {
                    count = i/2;
                }
                output[i] = output[count] + 1;
            }
        }

        return output;
    }
};

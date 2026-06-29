class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache;
        cache.push_back(1);
        cache.push_back(1);
        cache.push_back(2);
        int x = 1;
        if (n >= 3) {
            for (int i = 3; i <= n; i++) {
                x = cache[i - 1] + cache[i - 2];
                cache.push_back(x);
            }
        }

        return cache[n];

        
    }
};

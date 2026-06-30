class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        int minCost = 0;
        int x = cost[0];
        int y = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            minCost = min(x, y) + cost[i];
            x = y;
            y = minCost;
        }

        return min(x, y);
    }
};

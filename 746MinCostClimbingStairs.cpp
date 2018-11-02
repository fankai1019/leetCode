#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        std::vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + std::min(dp[i - 2], dp[i - 1]);
        }
        return std::min(dp[n - 1], dp[n - 2]);
    }
};

// This solution exceeded time limit for large vector input
class Solution2 {
   public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> cost1(cost.begin() + 1, cost.end());
        return std::min(minCost(cost), minCost(cost1));
    }

   private:
    int minCost(std::vector<int>& cost) {
        if (cost.size() < 3) return cost[0];
        int sum = cost[0];
        std::vector<int> vec1(cost.begin() + 1, cost.end());
        std::vector<int> vec2(cost.begin() + 2, cost.end());
        return sum + std::min(minCost(vec1), minCost(vec2));
    }
};

int main() {
    std::vector<int> input = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    //    std::vector<int> input = {0, 1, 2, 0};
    //    std::vector<int> input = {10, 15, 20};
    Solution a;
    std::cout << a.minCostClimbingStairs(input) << std::endl;
    return 0;
}

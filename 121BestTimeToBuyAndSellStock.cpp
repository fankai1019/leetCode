#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        int min = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            min = prices[i] < min ? prices[i] : min;
            profit = prices[i] - min > profit ? prices[i] - min : profit;
        }
        return profit;
    }
};

int main() {
    std::vector<int> input = {7, 1, 5, 3, 6, 4};
    Solution a;
    std::cout << a.maxProfit(input) << std::endl;
    return 0;
}

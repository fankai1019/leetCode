#include <iostream>
#include <vector>

class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        int sum = 0;
        for (int i = 0; !prices.empty() && i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i]) sum += prices[i + 1] - prices[i];
        }
        return sum;
    }
};

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution a;
    std::cout << a.maxProfit(prices) << std::endl;
    return 0;
}

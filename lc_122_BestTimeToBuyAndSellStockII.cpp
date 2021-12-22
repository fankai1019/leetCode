#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// if the best strategy is to buy at i and sell at j
// profit = prices[j] - prices[i]
// it is equivalent to profit = sum_k (prices[k+1] - prices[k]) k = i,...,j-1
// TC: O(n) loops through all elements
// SP: O(1) needs tmp variables for storage
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int diff = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
            diff += max(prices[i + 1] - prices[i], 0);
        return diff;
    }
};

int main()
{
    Solution s;
    vector<int> ivec = {7, 1, 5, 3, 6, 4};
    int result = s.maxProfit(ivec);
    cout << result << endl;
    return 0;
}

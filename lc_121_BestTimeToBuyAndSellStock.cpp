#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// DP
// best sell price after date i sell[i] = max(prices[i], sell[i+1])
// final answer is max(sell[i+1] - prices[i])
// iterative
// TC: O(n) loops through all elements
// SP: O(1) needs tmp variables for storage
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int best_sell_price = INT_MIN;
        int result = INT_MIN;
        for (int i = prices.size() - 1; i >= 0; --i)
        {
            if (i != prices.size() - 1)
                result = max(result, best_sell_price - prices[i]);
            if (i != 0)
                best_sell_price = max(prices[i], best_sell_price);
        }
        result = max(result, 0);
        return result;
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

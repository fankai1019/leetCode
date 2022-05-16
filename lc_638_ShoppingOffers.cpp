#include "utils.h"

using namespace std;

// Backtracking
// TC: O(2^(m + 1)) m number of valid offers
// SC: O(n) stack size is n regardless collection of results
class Solution
{
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        result = getPrice(price, needs);
        int sum = 0;
        backtracking(price, special, needs, sum);
        return result;
    }

private:
    void backtracking(const vector<int> &price, const vector<vector<int>> &special, vector<int> &needs, int &sum)
    {
        vector<bool> can_use_offer = canUseOffer(special, needs);
        int num_needs = accumulate(needs.begin(), needs.end(), 0);
        if (!num_needs)
        {
            result = min(result, sum);
            return;
        }

        for (int i = 0; i < special.size(); ++i)
        {
            if (can_use_offer[i])
            {
                for (int j = 0; j < needs.size(); ++j)
                    needs[j] -= special[i][j];
                sum += special[i][needs.size()];
                backtracking(price, special, needs, sum);
                for (int j = 0; j < needs.size(); ++j)
                    needs[j] += special[i][j];
                sum -= special[i][needs.size()];
            }
        }

        // handle left over
        int left_over = getPrice(price, needs);
        int total = sum + left_over;
        result = min(result, total);
        return;
    }

    vector<bool> canUseOffer(const vector<vector<int>> &special, const vector<int> &needs)
    {
        vector<bool> results(special.size(), true);
        for (int i = 0; i < special.size(); ++i)
        {

            const vector<int> &special_i = special[i];
            for (int j = 0; j < needs.size(); ++j)
            {
                if (needs[j] < special_i[j])
                {
                    results[i] = false;
                    break;
                }
            }
        }
        return results;
    }

    int getPrice(const vector<int> &price, const vector<int> &needs)
    {
        int sum = 0;
        for (int i = 0; i < needs.size(); ++i)
            sum += needs[i] * price[i];
        return sum;
    }
    int result = INT_MAX;
};

int main()
{
    // vector<int> price = {2, 3, 4};
    // vector<vector<int>> special = {{1, 1, 0, 4}, {2, 2, 1, 9}};
    // vector<int> needs = {1, 2, 1};
    vector<int> price = {2, 5};
    vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs = {3, 2};
    Solution s;
    int result = s.shoppingOffers(price, special, needs);
    cout << result << endl;
    return 0;
}

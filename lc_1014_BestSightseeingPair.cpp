#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// Brute force
// TC: O(n^2) loops over all (i, j) pairs (i < j)
// SC: O(n) it has two vectors of pairs
class Solution1
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        vector<pair<int, int>> pvec;
        for (size_t i = 0; i < values.size(); ++i)
            pvec.push_back(make_pair(values[i] + i, values[i] - i));
        int result = INT_MIN;
        for (size_t i = 0; i < values.size(); ++i)
        {
            for (size_t j = i + 1; j < values.size(); ++j)
            {
                int tmp = sum(pvec[i], pvec[j], i, j);
                if (result < tmp)
                    result = tmp;
            }
        }
        return result;
    }

private:
    int sum(const pair<int, int> &ipair, const pair<int, int> &jpair, int i, int j)
    {
        if (i < j)
            return ipair.first + jpair.second;
        return ipair.second + jpair.first;
    }
};

// DP
// our goal is to find max(A[i] + i + A[j] - j) (j > i)
// which is equivalent to find max(A[i] + i) and max(A[j] - j) (j > i)
// define max_after[j] as max(A[j] - j)
// max_after[j] = max(A[j] - j, max_after[j+1])
// final answer is max(A[i] + i, max_after[i])
// recursvie
// TC: O(n) within each stack, the num of operations is const
// SP: O(n) stack size
class Solution2
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int result = INT_MIN;
        vector<int> memo(values.size());
        max_after(values, 0, memo);
        for (int i = 0; i < values.size() - 1; ++i)
            result = max(result, values[i] + i + memo[i + 1]);
        return result;
    }

private:
    int max_after(const vector<int> &values, int i, vector<int> &memo)
    {
        if (i == values.size() - 1)
            return memo[i] = values.back() - i;
        return memo[i] = max(values[i] - i, max_after(values, i + 1, memo));
    }
};

// DP
// iterative
// TC: O(n) loops through all elements
// SP: O(1) needs tmp variables for storage
class Solution3
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int minus_max = INT_MIN;
        int result = INT_MIN;
        for (int i = values.size() - 1; i >= 0; --i)
        {
            if (i != values.size() - 1)
                result = max(result, values[i] + i + minus_max);
            if (i != 0)
                minus_max = max(minus_max, values[i] - i);
        }
        return result;
    }
};

int main()
{
    // Solution1 s;
    // Solution2 s;
    Solution3 s;
    vector<int> ivec = {8, 1, 5, 2, 6};
    int result = s.maxScoreSightseeingPair(ivec);
    cout << result << endl;
    return 0;
}

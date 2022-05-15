#include "utils.h"
using namespace std;

// Visited nodes
// Backtracking
// TC: O(10^n): we basically need to run through every number between [0, 10^n)
//     someone says it is O(n!) n < 10 and O(10!) n >= 10
// SC: O(n) recursion stack
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        for (int i = 1; i <= n; ++i)
        {
            vector<bool> visited(10, false);
            backtracking(i, i, visited);
        }
        return count + 1; // separated 0 from other cases to avoid leading zero
    }
    void backtracking(int n, int m, vector<bool> &visited)
    {
        if (m == 0)
        {
            count++;
            return;
        }
        int start = m == n ? 1 : 0;
        for (int i = start; i <= 9; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                backtracking(n, m - 1, visited);
                visited[i] = false;
            }
        }
    }
    int count = 0;
};

int main()
{
    int n = 2;
    Solution s;
    int result = s.countNumbersWithUniqueDigits(n);
    cout << result << endl;
    return 0;
}
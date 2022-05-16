#include "utils.h"

using namespace std;

// Backtracking
// TC: O(k) k: number of valid permutations
// SC: O(n) stack size is n regardless collection of results
class Solution
{
public:
    int countArrangement(int n)
    {
        vector<bool> visited(n + 1, false);
        backtracking(n, 1, visited);
        return count;
    }

    // i: current index in perm vec
    // At the end of each path when every number is processed, i == n+1 in last loop
    void backtracking(int n, int i, vector<bool> &visited)
    {
        if (i == n + 1)
        {
            count++;
            return;
        }

        for (int j = 1; j <= n; ++j)
        {
            if (j % i == 0 || i % j == 0)
            {
                if (!visited[j])
                {
                    visited[j] = true;
                    backtracking(n, i + 1, visited);
                    visited[j] = false;
                }
            }
        }
    }
    int count = 0;
};

int main()
{
    int n = 2;
    Solution s;
    int result = s.countArrangement(n);
    cout << result << endl;
    return 0;
}

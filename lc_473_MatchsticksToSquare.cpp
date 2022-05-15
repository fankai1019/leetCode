#include "utils.h"
using namespace std;

// Backtracking
// TC: O(4^n) each stick has 4 choices to be placed.
// SC: O(n) recursion stack
class Solution1
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int target = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        vector<bool> visited(matchsticks.size(), false);
        if (target % 4 != 0)
            return false;
        target /= 4;
        int sum = 0;
        int n = 4;
        backtracking(matchsticks, target, sum, n, 0, visited);
        return result;
    }

private:
    void backtracking(const vector<int> &matchsticks, int target,
                      int sum, int n, int begin, vector<bool> &visited)
    {
        if (result)
            return;
        if (n == 1)
        {
            result = true;
            return;
        }

        if (sum == target)
            backtracking(matchsticks, target, 0, n - 1, 0, visited);

        // it results in infinite loop if it starts from 0.
        // because assume we are at index i
        // once backtracking can not set result to true
        // then visited[i] will be reset to false
        // and for loop starts again from 0 and will will run into i again
        // for (int i = 0; i < matchsticks.size(); ++i)
        for (int i = begin; i < matchsticks.size(); ++i)
        {
            if (visited[i] || sum + matchsticks[i] > target)
                continue;

            visited[i] = true;
            backtracking(matchsticks, target, sum + matchsticks[i], n, i + 1, visited);
            visited[i] = false;
        }
    }
    bool result;
};

// Backtracking return from backtracking function
// TC: O(4^n): each stick has 4 choices to be placed.
// SC: O(n) recursion stack
class Solution2
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int target = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        vector<bool> visited(matchsticks.size(), false);
        if (target % 4 != 0)
            return false;
        target /= 4;
        int sum = 0;
        int n = 4;
        return backtracking(matchsticks, target, sum, n, 0, visited);
    }

private:
    bool backtracking(const vector<int> &matchsticks, int target,
                      int sum, int n, int begin, vector<bool> &visited)
    {
        if (n == 1)
            return true;

        if (sum == target)
            return backtracking(matchsticks, target, 0, n - 1, 0, visited);

        // it results in infinite loop if it starts from 0.
        // because assume we are at index i
        // once backtracking can not set result to true
        // then visited[i] will be reset to false
        // and for loop starts again from 0 and will will run into i again
        // for (int i = 0; i < matchsticks.size(); ++i)
        for (int i = begin; i < matchsticks.size(); ++i)
        {
            if (visited[i] || sum + matchsticks[i] > target)
                continue;

            visited[i] = true;
            if (backtracking(matchsticks, target, sum + matchsticks[i], n, i + 1, visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
};

int main()
{
    // vector<int> matchsticks = {1, 1, 2, 2, 2};
    vector<int> matchsticks = {5, 5, 5, 5, 16, 4, 4, 4, 4, 4, 3, 3, 3, 3, 4};
    // Solution1 s;
    Solution2 s;
    bool result = s.makesquare(matchsticks);
    cout << result << endl;
    return 0;
}
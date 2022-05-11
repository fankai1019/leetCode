#include "utils.h"

using namespace std;

// Backtracking
// TC: O(4^n*n) needs to loop over every possible combinations
//     a copy is needed when copying string to final results vector
// SC: O(n) stack frame size is n
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
            return {};

        string path;
        backTracking(results, path, digits, 0);
        return results;
    }

private:
    void backTracking(vector<string> &results, string &path, const string &digits, int pos)
    {
        if (pos == digits.size())
        {
            results.push_back(path);
            return;
        }

        string curr = mp[digits[pos] - '0'];
        for (int i = 0; i < curr.size(); ++i)
        {
            path.push_back(curr[i]);
            backTracking(results, path, digits, pos + 1);
            path.pop_back();
        }
    }
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> results;
};

int main()
{
    string digits = "23";
    Solution s;
    vector<string> results = s.letterCombinations(digits);
    printVec(results);
    return 0;
}

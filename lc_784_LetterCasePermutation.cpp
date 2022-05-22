#include "utils.h"
using namespace std;

// TC: O(2^n) worst case all charaters are letters and each node has 2 choices at each level
// SC: O(n) recursion stack frame size is n regardless final collection of results
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        string path;
        backtracking(s, path, 0);
        return results;
    }

private:
    void backtracking(const string &s, string &path, int start)
    {
        if (path.size() == s.size())
        {
            results.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                path.push_back(s[i]);
                backtracking(s, path, i + 1);
                path.pop_back();
            }
            else
            {
                path.push_back(toupper(s[i]));
                backtracking(s, path, i + 1);
                path.pop_back();
                path.push_back(tolower(s[i]));
                backtracking(s, path, i + 1);
                path.pop_back();
            }
        }
    }

    vector<string> results;
};

int main()
{
    string str = "a1b2";
    Solution s;
    vector<string> results = s.letterCasePermutation(str);
    printVec(results);
    return 0;
}
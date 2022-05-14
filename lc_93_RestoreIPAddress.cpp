#include "utils.h"

using namespace std;

// Binary search
// TC: O(3^4) stack size > 4 are terminated
// SC: O(1) stack frame size is 4
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> results;
        vector<string> path;
        backtracking(s, path, 0);
        for (int i = 0; i < str_vec.size(); ++i)
        {
            string str;
            for (int j = 0; j < str_vec[i].size(); ++j)
            {
                str += str_vec[i][j];
                if (j != str_vec[i].size() - 1)
                    str += ".";
            }
            results.push_back(str);
        }
        return results;
    }

private:
    void backtracking(const string &s, vector<string> &path, int begin)
    {
        if (path.size() == 4 && begin == s.size())
        {
            str_vec.push_back(path);
            return;
        }
        if (begin >= s.size())
            return;

        for (int i = 1; i <= 3; ++i)
        {
            if (begin + i - 1 >= s.size())
                continue;
            string sub_str = s.substr(begin, i);
            if (i > 1 && sub_str[0] == '0')
                continue;
            if (i == 3 && stoi(sub_str) > 255)
                continue;
            path.push_back(sub_str);
            backtracking(s, path, begin + i);
            path.pop_back();
        }
    }

    vector<vector<string>> str_vec;
};

int main()
{
    string str = "25525511135";
    Solution s;
    vector<string> results = s.restoreIpAddresses(str);
    printVec(results);

    return 0;
}
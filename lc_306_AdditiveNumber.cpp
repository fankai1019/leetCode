#include "utils.h"

using namespace std;

// Backtracking
// TC: O(C(n-1,2)) worst case is false.
//     it goes through all possible ways that the string can be separated into 3 substrings
//     and check whether the sum of first two equal the third one.
//     if there are n nums, there are c(n-1, 2) ways to separate them into 3 numbers
// SC: O(n) stack size is n regardless collection of results
class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        if (num.size() < 3)
            return false;
        vector<long long> path;
        backtracking(num, path, 0);
        return result;
    }

    void backtracking(const string &nums, vector<long long> &path, int index)
    {
        if (index == nums.size() && path.size() > 2)
            result = true;
        if (index >= nums.size())
            return;
        for (int i = index; i < nums.size(); ++i)
        {
            if (i - index + 1 > 17)
                break;
            if (i > index && nums[index] == '0')
                continue;
            long num = stoll(nums.substr(index, i - index + 1));
            int path_size = path.size();
            if (path_size < 2 || path[path_size - 1] + path[path_size - 2] == num)
            {
                path.push_back(num);
                backtracking(nums, path, i + 1);
                path.pop_back();
            }
        }
    }
    bool result = false;
};

int main()
{
    string num = "199100199";
    Solution s;
    bool result = s.isAdditiveNumber(num);
    cout << result << endl;
    return 0;
}

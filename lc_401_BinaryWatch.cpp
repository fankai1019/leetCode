#include "utils.h"
using namespace std;

// Backtracking
// TC: O(C(10, n)): at worst case there are C(10, n) combinations
// SC: O(n) recursion stack
class Solution1
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<int> path(10, 0);
        backtracking(turnedOn, path, 0);
        return results;
    }

private:
    void backtracking(int n, vector<int> &path, int begin)
    {
        if (n == 0)
        {
            int hours = binaryToNum(path, 0, 3);
            int mins = binaryToNum(path, 4, 9);
            if (0 <= hours && hours <= 11 && 0 <= mins && mins <= 59)
            {
                string time = to_string(hours);
                time += ":";
                if (mins < 10)
                    time += '0';
                time += to_string(mins);

                results.push_back(time);
            }
            return;
        }

        for (int i = begin; i <= 9; ++i)
        {
            path[i] = 1;
            backtracking(n - 1, path, i + 1);
            path[i] = 0;
        }
    }
    int binaryToNum(const vector<int> &nums, int begin, int end)
    {
        int sum = 0;
        for (int i = begin; i <= end; ++i)
        {
            if (nums[i])
                sum += pow(2, i - begin);
        }
        return sum;
    }

    vector<string> results;
};

// Better code structure
// Backtracking
// TC: O(C(10, n)): at worst case there are C(10, n) combinations
// SC: O(n) recursion stack
class Solution2
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<int> hours = {8, 4, 2, 1};
        vector<int> mins = {32, 16, 8, 4, 2, 1};
        pair<int, int> time(0, 0);
        backtracking(turnedOn, hours, mins, time, 0);
        return results;
    }

private:
    void backtracking(int n, const vector<int> &hours, const vector<int> &mins, pair<int, int> &time, int start)
    {
        if (n == 0)
            results.push_back(to_string(time.first) + ":" + (time.second < 10 ? "0" : "") + to_string(time.second));
        for (int i = start; i < hours.size() + mins.size(); ++i)
        {
            if (i < 4)
            {
                time.first += hours[i];
                if (time.first < 12)
                    backtracking(n - 1, hours, mins, time, i + 1);
                time.first -= hours[i];
            }
            else
            {
                time.second += mins[i - 4];
                if (time.second < 60)
                    backtracking(n - 1, hours, mins, time, i + 1);
                time.second -= mins[i - 4];
            }
        }
    }

    vector<string> results;
};

int main()
{
    int n = 1;
    // Solution1 s;
    Solution2 s;
    vector<string> results = s.readBinaryWatch(n);
    printVec(results);
    return 0;
}
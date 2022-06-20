#include "utils.h"
using namespace std;

// TC: O(Tnlog(26)) N number of tasks, T highest frequency, n cooldown period
// SC: O(26)
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < tasks.size(); ++i) // O(N)
            mp[tasks[i]]++;

        priority_queue<pair<int, char>> max_queue;
        for (const auto &it : mp)
            max_queue.push({it.second, it.first}); // O(26)

        int cycle = n + 1;

        int result = 0;

        // O(Tnlog(26))
        while (max_queue.size())
        {
            int time = 0;
            vector<pair<char, int>> tmp;
            for (int i = 0; i < cycle; ++i) // O(nlog(26))
            {
                if (max_queue.size())
                {
                    auto top = max_queue.top();
                    max_queue.pop();
                    tmp.push_back({top.second, top.first});
                    time++;
                }
            }

            for (int i = 0; i < tmp.size(); ++i)
            {
                if (--tmp[i].second)
                    max_queue.push({tmp[i].second, tmp[i].first});
            }
            result += max_queue.size() ? cycle : time;
        }
        return result;
    }
};

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    printVec(tasks);
    Solution s;
    int result = s.leastInterval(tasks, n);
    cout << result << endl;
    return 0;
}
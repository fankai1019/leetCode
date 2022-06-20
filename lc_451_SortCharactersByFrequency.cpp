#include "utils.h"
using namespace std;

// TC: O(nlogn)
// SC: O(n)
class Solution
{
public:
    string frequencySort(string s)
    {
        string result;
        unordered_map<char, int> cmap;
        priority_queue<pair<int, char>> max_pq;
        for (int i = 0; i < s.size(); ++i)
            cmap[s[i]]++;

        for (const auto &it : cmap)
            max_pq.push({it.second, it.first});

        while (max_pq.size())
        {
            result += string(max_pq.top().first, max_pq.top().second);
            max_pq.pop();
        }

        return result;
    }
};

int main()
{
    string str = "tree";
    Solution s;
    string result = s.frequencySort(str);
    cout << result << endl;
    return 0;
}
#include "utils.h"
using namespace std;

// TC: O(nlogn)
// SC: O(n)
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<string> results;
        priority_queue<int> max_queue;
        unordered_map<int, string> mp;
        for (int i = 0; i < score.size(); ++i)
            max_queue.push(score[i]);
        int count = 0;
        while (max_queue.size())
        {
            int top = max_queue.top();
            max_queue.pop();
            if (count == 0)
                mp[top] = "Gold Medal";
            else if (count == 1)
                mp[top] = "Silver Medal";
            else if (count == 2)
                mp[top] = "Bronze Medal";
            else
                mp[top] = to_string(count + 1);
            count++;
        }
        for (int i = 0; i < score.size(); ++i)
            results.push_back(mp[score[i]]);
        return results;
    }
};

int main()
{
    vector<int> score = {10, 3, 8, 9, 4};
    printVec(score);
    Solution s;
    vector<string> result = s.findRelativeRanks(score);
    printVec(result);
    return 0;
}
#include "utils.h"

using namespace std;

// Priority Queue Max Heap
// TC: O(mnlogk)
// SC: O(k)
class Solution
{
public:
    struct sumLess
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first + a.second < b.first + b.second;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> results;
        priority_queue<pair<int, int>, vector<pair<int, int>>, sumLess> max_q;

        for (int i = 0; i < min((int)nums1.size(), k); ++i)
        {
            for (int j = 0; j < min((int)nums2.size(), k); ++j)
            {
                if (max_q.size() < k)
                    max_q.push({nums1[i], nums2[j]});
                else if (max_q.top().first + max_q.top().second > nums1[i] + nums2[j])
                {
                    max_q.push({nums1[i], nums2[j]});
                    max_q.pop();
                }
                else
                    break;
            }
        }

        while (k-- && max_q.size())
        {
            results.push_back({max_q.top().first, max_q.top().second});
            max_q.pop();
        }
        return results;
    }
};

int main()
{
    vector<int> ivec1 = {1, 7, 11};
    vector<int> ivec2 = {2, 4, 6};
    int k = 3;
    Solution s;
    vector<vector<int>> result = s.kSmallestPairs(ivec1, ivec2, k);
    printVecVec(result);
    return 0;
}

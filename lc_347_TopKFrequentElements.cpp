#include "utils.h"

using namespace std;

// TC: O(kn)
// SC: O(n)
class Solution1
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); ++i) // O(n)
            mp[nums[i]]++;

        vector<int> results;
        // O(kn)
        while (k--)
        {
            int mx = -1;
            int value = -1;
            for (auto iter : mp)
            {
                if (iter.second > mx)
                {
                    mx = iter.second;
                    value = iter.first;
                }
            }
            results.push_back(value);
            mp.erase(value);
        }
        return results;
    }

private:
    unordered_map<int, int> mp;
};

// Priority Queue Max Heap
// TC: O(nlogK)
// SC: O(n)
class Solution2
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i) // O(n)
            mp[nums[i]]++;

        priority_queue<pair<int, int>> max_heap;

        vector<int> results;
        for (auto x : mp)
        {
            max_heap.push(make_pair(x.second, x.first)); // O(log(n-k))
            if (max_heap.size() > mp.size() - k)
            {
                results.push_back(max_heap.top().second);
                max_heap.pop();
            }
        }

        return results;
    }

private:
    unordered_map<int, int> mp;
};

// Priority Queue Min Heap
// TC: O(nlogK)
// SC: O(n)
class Solution3
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); ++i) // O(n)
            mp[nums[i]]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (auto x : mp)
        {
            min_heap.push(make_pair(x.second, x.first)); // O(logk)
            if (min_heap.size() > k)
                min_heap.pop();
        }

        vector<int> results;
        while (min_heap.size())
        {
            results.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return results;
    }

private:
    unordered_map<int, int> mp;
};

// TODO: Bucket Sort

int main()
{
    vector<int> ivec = {1, 1, 1, 2, 2, 3};
    int k = 2;
    // Solution1 s;
    // Solution2 s;
    Solution3 s;
    vector<int> result = s.topKFrequent(ivec, k);
    printVec(result);
    return 0;
}

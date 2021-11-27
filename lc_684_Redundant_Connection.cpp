#include <iostream>
#include <vector>
using namespace std;

class UF
{
public:
    UF(size_t n)
    {
        for (size_t i = 0; i < n; ++i)
        {
            parents_.push_back(i);
            ranks_.push_back(0);
        }
    }

    int find(int x)
    {
        if (x != parents_[x])
            parents_[x] = find(parents_[x]);
        return parents_[x];
    }

    bool merge(int x, int y)
    {
        int parent1 = find(x);
        int parent2 = find(y);
        if (parent1 == parent2)
            return false;
        if (ranks_[parent1] > ranks_[parent2])
            parents_[parent1] = parent2;
        else if (ranks_[parent2] > ranks_[parent1])
            parents_[parent2] = parent1;
        else
        {
            parents_[parent1] = parent2;
            ranks_[parent2]++;
        }
        return true;
    }

private:
    vector<int> parents_;
    vector<int> ranks_;
};

// TC: O(n), we need to traverse all edges once and UF union and find takes roughly O(1)
// SC: O(n), we need to store parents and ranks
class Solution
{
public:
    vector<int> redundantConnection(const vector<vector<int>> &edges)
    {
        UF uf(edges.size() + 1);
        for (const auto &e : edges)
        {
            if (!uf.merge(e[0], e[1]))
                return e;
        }
        return {};
    }
};

int main()
{
    vector<vector<int>> edges{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    Solution s;
    vector<int> results = s.redundantConnection(edges);
    cout << "[" << results[0] << ", " << results[1] << "]" << endl;
    return 0;
}
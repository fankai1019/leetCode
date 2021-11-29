#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class UF
{
public:
    UF(int n)
        : parents_(n), ranks_(n, 0)
    {
        iota(parents_.begin(), parents_.end(), 0);
    }

    int find(int x)
    {
        if (x != parents_[x])
            parents_[x] = find(parents_[x]);
        return parents_[x];
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        int parent1 = find(x);
        int parent2 = find(y);

        if (parent1 == parent2)
            return false;

        int rank1 = ranks_[parent1];
        int rank2 = ranks_[parent2];

        if (rank1 < rank2)
            parents_[parent1] = parent2;
        else if (rank2 < rank1)
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

// TC: O(ElogE + QlogQ), we need to sort the edges and queries
// SC: O(n), we need to store those equations
class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edge_list, vector<vector<int>> &queries)
    {
        // for indexing
        for (size_t i = 0; i < queries.size(); ++i)
            queries[i].push_back(i);

        // sort the edge list from small distance to large distance
        sort(edge_list.begin(), edge_list.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });
        // sort queries from low limit high limit
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        UF uf(n);
        vector<bool> results(queries.size());
        int j = 0; // NB: all edges are visited once
        for (size_t i = 0; i < queries.size(); ++i)
        {
            const vector<int> &q = queries[i];
            int u = q[0];
            int v = q[1];
            int limit = q[2];
            int index = q[3];
            for (; j < edge_list.size() && edge_list[j][2] < limit; ++j)
                uf.merge(edge_list[j][0], edge_list[j][1]);
            results[index] = uf.isConnected(u, v);
        }
        return results;
    }

private:
    vector<int> parents_;
};

int main()
{
    // int n = 3;
    // vector<vector<int>> edge_list = {{0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 16}};
    // vector<vector<int>> queries = {{0, 1, 2}, {0, 2, 5}};
    int n = 5;
    vector<vector<int>> edge_list = {{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}};
    vector<vector<int>> queries = {{0, 4, 14}, {1, 4, 13}};
    Solution s;
    vector<bool> result = s.distanceLimitedPathsExist(n, edge_list, queries);
    for (const auto &e : result)
        cout << e << " ";
    cout << endl;
    return 0;
}
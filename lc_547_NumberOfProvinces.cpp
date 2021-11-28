#include <iostream>
#include <set>
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

// TC: O(n^2), we need to traverse half of the matrix.
// SC: O(n), we need to store parents and ranks
class Solution
{
public:
    int numOfProvinces(const vector<vector<int>> &cities)
    {
        UF uf(cities.size());
        for (size_t i = 0; i < cities.size(); ++i)
        {
            for (size_t j = 0; j < cities.size(); ++j)
                if (i != j)
                    if (cities[i][j])
                        uf.merge(i, j);
        }

        set<int> groups;
        for (size_t i = 0; i < cities.size(); ++i)
            groups.insert(uf.find(i));

        return groups.size();
    }
};

int main()
{
    vector<vector<int>> edges{
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};
    Solution s;
    int result = s.numOfProvinces(edges);
    cout << result << endl;
    return 0;
}
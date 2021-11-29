#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

// Be careful if the characters in a string are not unique
class UF
{
public:
    UF(const string &str)
    {
        for (size_t i = 0; i < str.size(); ++i)
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

// TC: O(nlogn), we need to sort a list
// SC: O(n), we need to store those equations
class Solution
{
public:
    string smallestStringWithSwaps(const string &s, const vector<vector<int>> &pairs)
    {
        UF uf(s);
        for (const auto &pair : pairs)
        {
            int x = pair[0];
            int y = pair[1];
            uf.merge(x, y);
        }

        unordered_map<int, list<char>> pc_map;
        for (size_t i = 0; i < s.size(); ++i)
        {
            int parent = uf.find(i);
            pc_map[parent].push_back(s[i]);
        }
        for (auto &e : pc_map)
            e.second.sort();

        string result;
        for (size_t i = 0; i < s.size(); ++i)
        {
            int parent = uf.find(i);
            result.push_back(*pc_map[parent].begin());
            pc_map[parent].pop_front();
        }
        return result;
    }
};

int main()
{
    const string str = "dcab";
    vector<vector<int>> pairs = {{0, 3}, {1, 2}};
    // const string str = "dcab";
    // vector<vector<int>> pairs = {{0, 3}, {1, 2}, {0, 2}};
    // const string str = "udyyek";
    // vector<vector<int>> pairs = {{3, 3}, {3, 0}, {5, 1}, {3, 1}, {3, 4}, {3, 5}};
    // const string str = "nhrqzrqhxvblouv";
    // vector<vector<int>> pairs = {{8, 6}, {7, 4}, {1, 8}, {9, 5}, {13, 2}, {11, 12}, {7, 1}, {2, 13}, {13, 7}, {12, 5}, {13, 13}, {2, 11}, {14, 12}, {6, 11}, {6, 3}};

    Solution s;
    string result = s.smallestStringWithSwaps(str, pairs);
    cout << result << endl;
    return 0;
}